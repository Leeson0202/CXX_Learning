/**
 * @file RPCServer.h
 * @brief RPC服务器头文件，定义了RPC服务器的核心类和接口
 * 
 * 这个文件实现了一个简单但功能完整的RPC服务器框架，
 * 支持方法注册、客户端连接处理、RPC方法执行等核心功能。
 * 服务器使用socket进行通信，采用多线程模型处理并发请求。
 */
#ifndef RPC_SERVER_H
#define RPC_SERVER_H

#include <string>
#include <unordered_map>
#include <functional>
#include <memory>
#include <thread>
#include <atomic>
#include <vector> // 添加vector头文件引用，用于参数列表

/**
 * @class RPCServer
 * @brief RPC服务器类，提供RPC服务的核心功能
 * 
 * 这个类负责：
 * - 启动和停止RPC服务
 * - 注册可供客户端调用的RPC方法
 * - 处理客户端连接和请求
 * - 执行远程方法调用并返回结果
 */
class RPCServer {
public:
    /**
     * @brief 构造函数，创建RPC服务器实例
     * @param port 服务器监听端口，默认8080
     * 
     * 初始化服务器配置，设置监听端口，
     * 准备服务器运行所需的各项资源。
     */
    explicit RPCServer(int port = 8080);
    
    /**
     * @brief 析构函数，清理服务器资源
     * 
     * 确保服务器在销毁时能够正确停止，
     * 释放所有分配的资源，避免资源泄漏。
     */
    ~RPCServer();
    
    /**
     * @brief 启动RPC服务器
     * @return bool 启动是否成功
     * 
     * 创建并启动服务器线程，开始监听指定端口的客户端连接。
     * 成功启动返回true，失败返回false。
     */
    bool start();
    
    /**
     * @brief 停止RPC服务器
     * 
     * 通知服务器停止运行，关闭监听socket，
     * 等待服务器线程结束，释放资源。
     */
    void stop();
    
    /**
     * @brief 注册RPC方法供客户端调用
     * @tparam Func 函数类型模板参数
     * @param name 方法名称，客户端通过此名称调用
     * @param func 实际执行的函数对象
     * 
     * 将函数对象与名称关联并存储在方法映射表中，
     * 客户端可以通过发送此方法名来调用对应的函数。
     * 函数必须接受vector<string>参数并返回string。
     */
    template<typename Func>
    void registerMethod(const std::string& name, Func func);
    
    /**
     * @brief 等待服务器停止
     * 
     * 阻塞当前线程，直到服务器停止运行，
     * 通常用于主函数中保持程序运行直到收到停止信号。
     */
    void waitForShutdown();
    
private:
    int port_;                              //!< 服务器监听端口号
    std::atomic<bool> running_;             //!< 服务器运行状态标志，true表示运行中
    std::unique_ptr<std::thread> server_thread_; //!< 服务器主循环线程
    
    /**
     * @brief 方法映射表
     * 
     * 存储方法名到函数对象的映射，
     * 键为方法名称字符串，值为对应的函数对象。
     * 函数接受参数列表并返回字符串结果。
     */
    std::unordered_map<std::string, std::function<std::string(const std::vector<std::string>&)>> methods_;
    
    /**
     * @brief 服务器主循环
     * 
     * 创建监听socket，接受客户端连接，
     * 为每个连接创建新线程进行处理。
     * 这是服务器的核心运行逻辑。
     */
    void serverLoop();
    
    /**
     * @brief 处理单个客户端连接
     * @param client_socket 客户端socket文件描述符
     * 
     * 从客户端读取请求，解析请求内容，
     * 调用相应的方法，将结果返回给客户端。
     * 处理完请求后关闭连接。
     */
    void handleClient(int client_socket);
    
    /**
     * @brief 执行注册的RPC方法
     * @param method_name 要执行的方法名
     * @param args 方法参数列表
     * @return string 方法执行结果
     * 
     * 查找并执行指定名称的RPC方法，
     * 将参数传递给方法，捕获执行结果并返回。
     * 如果方法不存在或执行出错，返回错误信息。
     */
    std::string executeMethod(const std::string& method_name, const std::vector<std::string>& args);
};

/**
 * @brief 模板方法registerMethod的实现
 * @tparam Func 函数类型模板参数
 * @param name 方法名称
 * @param func 函数对象
 * 
 * 将函数对象转换为统一的函数类型并存储在methods_映射表中，
 * 这样客户端就可以通过名称调用对应的函数。
 */
template<typename Func>
void RPCServer::registerMethod(const std::string& name, Func func) {
    // 直接将传入的函数存储到methods_映射表中
    // 假设传入的函数已经是std::function<std::string(const std::vector<std::string>&)>类型
    methods_[name] = func;
}

#endif // RPC_SERVER_H