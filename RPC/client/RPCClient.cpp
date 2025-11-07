/**
 * @file RPCClient.cpp
 * @brief RPC客户端实现文件
 * 
 * 这个文件实现了RPCClient类中声明的所有方法，
 * 包括建立连接、断开连接、发送RPC请求和接收响应等核心功能。
 * 客户端负责网络通信、请求序列化、响应反序列化等操作。
 */
#include "RPCClient.h"
#include "../include/RPCCommon.h"
#include <iostream>
#include <sys/socket.h>    // Socket相关头文件
#include <netinet/in.h>    // 网络地址结构
#include <arpa/inet.h>     // 网络地址转换函数
#include <unistd.h>        // 系统调用，如close、read、write等
#include <cstring>         // 字符串操作函数
#include <vector>          // 向量容器，用于存储参数列表

/**
 * @brief RPCClient构造函数实现
 * @param server_address 服务器地址
 * @param port 服务器端口
 * 
 * 初始化客户端的成员变量，设置服务器地址和端口，
 * 初始化socket文件描述符为-1，表示未连接状态，
 * 连接标志为false，请求ID为0。
 */
RPCClient::RPCClient(const std::string& server_address, int port) 
    : server_address_(server_address), port_(port), socket_fd_(-1), connected_(false), request_id_(0) {
}

/**
 * @brief RPCClient析构函数实现
 * 
 * 在客户端销毁时调用disconnect方法，
 * 确保断开与服务器的连接，释放网络资源。
 */
RPCClient::~RPCClient() {
    disconnect();
}

/**
 * @brief 连接到RPC服务器
 * @return bool 连接是否成功
 * 
 * 如果已经连接，则直接返回true；
 * 否则创建socket，设置服务器地址，
 * 尝试连接到服务器，并更新连接状态。
 */
bool RPCClient::connect() {
    // 检查是否已经连接
    if (connected_) {
        return true;
    }
    
    // 创建TCP socket
    socket_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd_ < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        return false;
    }
    
    // 设置服务器地址结构
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;           // IPv4地址族
    server_address.sin_port = htons(port_);        // 将主机字节序转换为网络字节序
    
    // 将点分十进制IP地址转换为网络字节序
    if (inet_pton(AF_INET, server_address_.c_str(), &server_address.sin_addr) <= 0) {
        std::cerr << "Invalid address or address not supported" << std::endl;
        close(socket_fd_);
        socket_fd_ = -1;
        return false;
    }
    
    // 连接到服务器
    if (::connect(socket_fd_, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        close(socket_fd_);
        socket_fd_ = -1;
        return false;
    }
    
    // 更新连接状态并输出连接信息
    connected_ = true;
    std::cout << "Connected to RPC server at " << server_address_ << ":" << port_ << std::endl;
    return true;
}

/**
 * @brief 断开与RPC服务器的连接
 * 
 * 如果当前已连接，则关闭socket，
 * 重置socket文件描述符，更新连接状态，
 * 并输出断开连接的信息。
 */
void RPCClient::disconnect() {
    // 检查是否已连接
    if (connected_) {
        // 关闭socket，释放网络资源
        close(socket_fd_);
        socket_fd_ = -1;        // 重置文件描述符
        connected_ = false;     // 更新连接状态
        std::cout << "Disconnected from RPC server" << std::endl;
    }
}

/**
 * @brief 调用远程RPC方法
 * @param method_name 要调用的方法名称
 * @param arguments 方法参数列表
 * @return std::string 方法执行结果或错误信息
 * 
 * 首先检查连接状态，如果未连接则尝试连接；
 * 然后创建RPC请求，序列化并发送到服务器；
 * 接收服务器响应，反序列化并处理结果；
 * 如果发生错误，处理异常并返回错误信息。
 */
std::string RPCClient::callMethod(const std::string& method_name, const std::vector<std::string>& arguments) {
    // 检查连接状态，如果未连接则尝试连接
    if (!connected_ && !connect()) {
        return "Failed to connect to server";
    }
    
    // 创建RPC请求对象
    RPCRequest request;
    request.method_name = method_name;      // 设置方法名
    request.arguments = arguments;          // 设置参数列表
    request.request_id = getNextRequestId(); // 获取唯一请求ID
    
    // 序列化请求对象为字符串
    std::string request_data = serializeRequest(request);
    
    // 发送请求到服务器
    if (send(socket_fd_, request_data.c_str(), request_data.length(), 0) < 0) {
        std::cerr << "Send failed" << std::endl;
        disconnect(); // 发送失败，断开连接
        return "Failed to send request";
    }
    
    // 接收服务器响应
    char buffer[1024] = {0};               // 缓冲区用于存储接收的数据
    int bytes_read = read(socket_fd_, buffer, 1024);
    
    // 检查接收是否成功
    if (bytes_read <= 0) {
        std::cerr << "Receive failed" << std::endl;
        disconnect(); // 接收失败，断开连接
        return "Failed to receive response";
    }
    
    // 反序列化响应数据
    std::string response_data(buffer, bytes_read);
    RPCResponse response = deserializeResponse(response_data);
    
    // 根据响应状态返回结果或错误信息
    if (response.success) {
        return response.result;             // 成功，返回执行结果
    } else {
        return "Error: " + response.error_message; // 失败，返回错误信息
    }
}

/**
 * @brief 检查客户端连接状态
 * @return bool 当前连接状态
 * 
 * 返回connected_成员变量的值，
 * 表示客户端是否已连接到服务器。
 */
bool RPCClient::isConnected() const {
    return connected_;
}

/**
 * @brief 获取下一个请求ID
 * @return int 递增后的请求ID
 * 
 * 递增并返回请求ID，每次调用都会生成一个新的唯一ID，
 * 用于标识RPC请求，确保请求和响应能够正确匹配。
 */
int RPCClient::getNextRequestId() {
    return ++request_id_;
}