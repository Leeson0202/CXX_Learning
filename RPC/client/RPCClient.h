/**
 * @file RPCClient.h
 * @brief RPC客户端头文件
 * 
 * 这个文件定义了RPCClient类，用于创建RPC客户端连接，
 * 发送远程过程调用请求，并接收服务器响应。
 * 客户端负责建立网络连接、序列化请求、发送请求、接收响应和反序列化响应。
 */
#ifndef RPC_CLIENT_H
#define RPC_CLIENT_H

#include <string>
#include <vector>

/**
 * @brief RPC客户端类
 * 
 * 提供与RPC服务器通信的功能，负责建立连接、发送RPC请求和接收响应。
 * 支持基本的网络操作，如连接、断开连接和方法调用。
 */
class RPCClient {
public:
    /**
     * @brief 构造函数
     * @param server_address 服务器IP地址或主机名
     * @param port 服务器监听端口，默认为8080
     * 
     * 初始化RPC客户端，设置服务器地址和端口，
     * 初始化连接状态为未连接，请求ID为0。
     */
    RPCClient(const std::string& server_address, int port = 8080);
    
    /**
     * @brief 析构函数
     * 
     * 确保在销毁客户端时断开连接，
     * 释放网络资源。
     */
    ~RPCClient();
    
    /**
     * @brief 连接到RPC服务器
     * @return bool 连接是否成功
     * 
     * 创建socket，设置服务器地址，
     * 尝试连接到指定的服务器地址和端口。
     */
    bool connect();
    
    /**
     * @brief 断开与服务器的连接
     * 
     * 如果当前已连接，则关闭socket，
     * 释放网络资源，设置连接状态为未连接。
     */
    void disconnect();
    
    /**
     * @brief 调用远程RPC方法
     * @param method_name 要调用的远程方法名称
     * @param arguments 方法参数列表
     * @return std::string 方法执行结果
     * 
     * 检查连接状态，如果已连接，则序列化RPC请求，
     * 发送给服务器，等待并接收响应，反序列化响应，
     * 返回方法执行结果。
     */
    std::string callMethod(const std::string& method_name, const std::vector<std::string>& arguments);
    
    /**
     * @brief 检查是否已连接到服务器
     * @return bool 当前连接状态
     * 
     * 返回客户端的连接状态，true表示已连接，false表示未连接。
     */
    bool isConnected() const;
    
private:
    std::string server_address_;  // 服务器地址（IP或主机名）
    int port_;                   // 服务器监听端口
    int socket_fd_;              // 套接字文件描述符，用于网络通信
    bool connected_;             // 连接状态标志，true表示已连接
    int request_id_;             // 请求ID，用于匹配请求和响应，确保响应的正确性
    
    /**
     * @brief 获取下一个请求ID
     * @return int 递增后的请求ID
     * 
     * 递增并返回请求ID，用于标识每个RPC请求，
     * 确保请求和响应能够正确匹配。
     */
    int getNextRequestId();
};

#endif // RPC_CLIENT_H