/**
 * @file RPCServer.cpp
 * @brief RPC服务器实现文件
 * 
 * 这个文件实现了RPCServer类中声明的所有方法，
 * 包括服务器启动、停止、连接处理、方法执行等核心功能。
 * 同时实现了日志记录功能，用于跟踪和调试RPC请求处理过程。
 */
#include "RPCServer.h"
#include "../include/RPCCommon.h"
#include <iostream>
#include <sys/socket.h>    // Socket相关头文件
#include <netinet/in.h>    // 网络地址结构
#include <arpa/inet.h>     // 网络地址转换函数
#include <unistd.h>        // 系统调用，如close、read、write等
#include <cstring>         // 字符串操作函数
#include <sstream>         // 字符串流操作
#include <iomanip>         // 输入输出流格式化
#include <chrono>          // 时间相关功能

/**
 * @brief 获取当前时间戳
 * @return std::string 格式化的时间戳字符串，格式为YYYY-MM-DD HH:MM:SS
 * 
 * 使用C++11的chrono库获取当前系统时间，
 * 并格式化为人类可读的字符串形式，用于日志记录。
 */
std::string getCurrentTimestamp() {
    // 获取当前系统时间点
    auto now = std::chrono::system_clock::now();
    // 转换为time_t类型
    auto now_time = std::chrono::system_clock::to_time_t(now);
    // 转换为本地时间结构
    auto now_tm = std::localtime(&now_time);
    
    // 使用stringstream格式化时间
    std::stringstream ss;
    ss << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

/**
 * @brief 记录日志信息
 * @param level 日志级别，如INFO、DEBUG、ERROR等
 * @param message 日志消息内容
 * 
 * 格式化并输出日志信息，包括时间戳和日志级别，
 * 用于跟踪RPC服务器的运行状态和请求处理过程。
 */
void logMessage(const std::string& level, const std::string& message) {
    std::cout << "[" << getCurrentTimestamp() << "] [" << level << "] " << message << std::endl;
}

/**
 * @brief RPCServer构造函数
 * @param port 服务器监听端口
 * 
 * 初始化RPCServer实例，设置监听端口，
 * 初始化运行状态标志为false。
 */
RPCServer::RPCServer(int port) : port_(port), running_(false) {
}

/**
 * @brief RPCServer析构函数
 * 
 * 确保服务器在销毁时停止运行，
 * 调用stop()方法清理资源。
 */
RPCServer::~RPCServer() {
    stop();
}

/**
 * @brief 启动RPC服务器
 * @return bool 启动是否成功
 * 
 * 如果服务器已在运行，则直接返回true；
 * 否则设置运行标志为true，创建并启动服务器线程，
 * 开始执行serverLoop()方法。
 */
bool RPCServer::start() {
    // 检查服务器是否已经在运行
    if (running_) {
        return true;
    }
    
    // 设置运行标志并创建服务器线程
    running_ = true;
    server_thread_.reset(new std::thread(&RPCServer::serverLoop, this));
    
    // 输出启动信息
    std::cout << "RPC Server started on port " << port_ << std::endl;
    return true;
}

/**
 * @brief 停止RPC服务器
 * 
 * 如果服务器未运行，则直接返回；
 * 否则设置运行标志为false，等待服务器线程结束，
 * 确保所有资源都被正确释放。
 */
void RPCServer::stop() {
    // 检查服务器是否正在运行
    if (!running_) {
        return;
    }
    
    // 设置停止标志并等待线程结束
    running_ = false;
    if (server_thread_ && server_thread_->joinable()) {
        server_thread_->join();
    }
    
    // 输出停止信息
    std::cout << "RPC Server stopped" << std::endl;
}

/**
 * @brief 等待服务器停止
 * 
 * 阻塞当前线程，直到服务器线程结束，
 * 通常在主函数中使用，用于保持程序运行直到服务器停止。
 */
void RPCServer::waitForShutdown() {
    if (server_thread_ && server_thread_->joinable()) {
        server_thread_->join();
    }
}

/**
 * @brief 服务器主循环
 * 
 * 创建监听socket，设置地址复用，绑定端口，开始监听，
 * 使用select函数进行非阻塞IO，接受客户端连接，
 * 为每个连接调用handleClient方法进行处理。
 * 服务器循环运行直到收到停止信号。
 */
void RPCServer::serverLoop() {
    // 创建TCP socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        return;
    }
    
    // 设置地址复用，避免端口占用问题
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        std::cerr << "setsockopt failed" << std::endl;
        close(server_fd);
        return;
    }
    
    // 配置服务器地址结构
    struct sockaddr_in address;
    address.sin_family = AF_INET;           // IPv4地址族
    address.sin_addr.s_addr = INADDR_ANY;   // 监听所有网络接口
    address.sin_port = htons(port_);        // 将主机字节序转换为网络字节序
    
    // 绑定socket到指定端口
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        close(server_fd);
        return;
    }
    
    // 开始监听，最大连接队列长度为3
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        close(server_fd);
        return;
    }
    
    // 主循环，持续接受连接直到收到停止信号
    while (running_) {
        // 使用select进行非阻塞监听，以便能够响应stop()调用
        fd_set read_fds;        // 文件描述符集合
        struct timeval tv;      // 超时时间设置
        
        FD_ZERO(&read_fds);     // 清空文件描述符集合
        FD_SET(server_fd, &read_fds);  // 添加监听socket到集合
        
        // 设置超时时间为1秒
        tv.tv_sec = 1;  // 1秒超时
        tv.tv_usec = 0;
        
        // 调用select等待可读事件
        int activity = select(server_fd + 1, &read_fds, NULL, NULL, &tv);
        
        // 检查是否收到停止信号
        if (!running_) {
            break;  // 如果收到停止信号，退出循环
        }
        
        // 检查select是否出错
        if (activity < 0) {
            continue;  // 错误发生，继续下一次循环
        }
        
        // 检查是否有新的连接请求
        if (FD_ISSET(server_fd, &read_fds)) {
            int client_socket;              // 客户端socket描述符
            struct sockaddr_in client_address;  // 客户端地址
            socklen_t addrlen = sizeof(client_address);
            
            // 接受客户端连接
            client_socket = accept(server_fd, (struct sockaddr *)&client_address, &addrlen);
            if (client_socket < 0) {
                std::cerr << "Accept failed" << std::endl;
                continue;
            }
            
            // 处理客户端连接
            handleClient(client_socket);
        }
    }
    
    // 关闭监听socket
    close(server_fd);
}

/**
 * @brief 处理客户端连接和请求
 * @param client_socket 客户端socket描述符
 * 
 * 从客户端读取请求数据，反序列化请求，记录请求信息，
 * 调用executeMethod执行RPC方法，构造响应，记录响应信息，
 * 序列化响应并发送给客户端，最后关闭连接。
 */
void RPCServer::handleClient(int client_socket) {
    // 缓冲区用于存储读取的请求数据
    char buffer[1024] = {0};
    int bytes_read = read(client_socket, buffer, 1024);
    
    // 检查读取是否成功
    if (bytes_read <= 0) {
        close(client_socket);
        return;
    }
    
    // 将缓冲区数据转换为字符串
    std::string request_data(buffer, bytes_read);
    // 反序列化请求
    RPCRequest request = deserializeRequest(request_data);
    
    // 记录请求信息 - 打点日志
    std::stringstream log_ss1;
    log_ss1 << "Received request [" << request.request_id << "]: method=" << request.method_name;
    logMessage("INFO", log_ss1.str());
    
    // 构建参数字符串用于日志
    std::stringstream params_ss;
    params_ss << "params=[";
    for (size_t i = 0; i < request.arguments.size(); ++i) {
        params_ss << request.arguments[i];
        if (i < request.arguments.size() - 1) {
            params_ss << ", ";
        }
    }
    params_ss << "]";
    std::stringstream log_ss2;
    log_ss2 << "Request details [" << request.request_id << "]: " << params_ss.str();
    logMessage("INFO", log_ss2.str());
    
    // 执行RPC方法
    std::string result = executeMethod(request.method_name, request.arguments);
    
    // 构造响应
    RPCResponse response;
    response.request_id = request.request_id;
    response.success = !result.empty();
    response.result = result;
    
    // 设置错误信息（如果失败）
    if (!response.success) {
        response.error_message = "Method execution failed";
    }
    
    // 记录响应信息 - 打点日志
    std::stringstream log_ss3;
    if (response.success) {
        log_ss3 << "Request [" << request.request_id << "] completed successfully, result=" << result;
        logMessage("INFO", log_ss3.str());
    } else {
        log_ss3 << "Request [" << request.request_id << "] failed: " << response.error_message;
        logMessage("ERROR", log_ss3.str());
    }
    
    // 序列化响应并发送
    std::string response_data = serializeResponse(response);
    send(client_socket, response_data.c_str(), response_data.length(), 0);
    
    // 关闭客户端连接
    close(client_socket);
}

/**
 * @brief 执行RPC方法
 * @param method_name 要执行的方法名称
 * @param args 方法参数列表
 * @return std::string 方法执行结果
 * 
 * 在方法映射表中查找指定名称的方法，如果找到则执行，
 * 记录方法执行开始和结束的日志，捕获并记录可能的异常，
 * 返回方法执行结果或空字符串（如果方法不存在或执行失败）。
 */
std::string RPCServer::executeMethod(const std::string& method_name, const std::vector<std::string>& args) {
    // 在方法映射表中查找方法
    auto it = methods_.find(method_name);
    if (it != methods_.end()) {
        try {
            // 记录方法执行开始
            std::stringstream log_ss4;
            log_ss4 << "Executing method: " << method_name;
            logMessage("DEBUG", log_ss4.str());
            
            // 执行方法并获取结果
            std::string result = it->second(args);
            
            // 记录方法执行完成
            std::stringstream log_ss5;
            log_ss5 << "Method execution completed: " << method_name;
            logMessage("DEBUG", log_ss5.str());
            return result;
        } catch (const std::exception& e) {
            // 记录异常信息
            std::stringstream log_ss6;
            log_ss6 << "Exception in method " << method_name << ": " << e.what();
            logMessage("ERROR", log_ss6.str());
            return "";
        }
    }
    
    // 记录方法未找到的错误
    std::stringstream log_ss7;
    log_ss7 << "Method not found: " << method_name;
    logMessage("ERROR", log_ss7.str());
    return "";  // 返回空字符串表示失败
}