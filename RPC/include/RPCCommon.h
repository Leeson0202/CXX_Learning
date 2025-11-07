/**
 * @file RPCCommon.h
 * @brief RPC框架公共组件和协议定义文件
 * 
 * 这个文件定义了RPC框架中客户端和服务器共享的核心组件，
 * 包括消息类型枚举、请求和响应结构体、错误码定义，
 * 以及序列化和反序列化工具函数声明。
 * 这些组件确保了客户端和服务器之间的通信协议一致性。
 */
#ifndef RPC_COMMON_H
#define RPC_COMMON_H

#include <string>
#include <vector>
#include <cstdint>

/**
 * @brief RPC调用的消息类型枚举
 * 
 * 定义了RPC通信中可能的消息类型，
 * 用于区分请求消息、响应消息和错误消息。
 */
enum class MessageType {
    REQUEST = 0,   // RPC请求消息
    RESPONSE = 1,  // RPC响应消息
    ERROR = 2      // 错误消息
};

/**
 * @brief RPC请求结构
 * 
 * 定义了RPC客户端发送给服务器的请求格式，
 * 包含方法名称、参数列表和请求ID。
 */
struct RPCRequest {
    std::string method_name;            // 要调用的远程方法名称
    std::vector<std::string> arguments; // 方法的参数列表，字符串形式
    int request_id;                     // 唯一请求ID，用于匹配请求和响应
};

/**
 * @brief RPC响应结构
 * 
 * 定义了RPC服务器发送给客户端的响应格式，
 * 包含执行结果、成功状态、错误信息和对应的请求ID。
 */
struct RPCResponse {
    std::string result;                 // 方法执行结果，字符串形式
    bool success;                       // 执行是否成功的标志
    std::string error_message;          // 错误信息（如果执行失败）
    int request_id;                     // 对应的请求ID，用于匹配
};

/**
 * @brief RPC框架的错误码枚举
 * 
 * 定义了RPC框架可能遇到的各种错误类型，
 * 用于统一错误处理和错误信息传递。
 */
enum class RPCErrorCode {
    OK = 0,                     // 操作成功
    NETWORK_ERROR = 1,          // 网络通信错误
    SERVER_ERROR = 2,           // 服务器内部错误
    METHOD_NOT_FOUND = 3,       // 请求的方法不存在
    PARAMETER_ERROR = 4,        // 参数错误或无效
    SERIALIZATION_ERROR = 5     // 序列化或反序列化错误
};

/**
 * @brief 序列化RPC请求
 * @param request RPCRequest结构体对象
 * @return std::string 序列化后的字符串
 * 
 * 将RPCRequest结构体转换为字符串形式，
 * 以便在网络上传输。
 */
std::string serializeRequest(const RPCRequest& request);

/**
 * @brief 反序列化RPC请求
 * @param data 序列化的字符串数据
 * @return RPCRequest 反序列化后的RPCRequest对象
 * 
 * 将字符串形式的请求数据转换回RPCRequest结构体，
 * 用于服务器解析客户端请求。
 */
RPCRequest deserializeRequest(const std::string& data);

/**
 * @brief 序列化RPC响应
 * @param response RPCResponse结构体对象
 * @return std::string 序列化后的字符串
 * 
 * 将RPCResponse结构体转换为字符串形式，
 * 以便在网络上传输。
 */
std::string serializeResponse(const RPCResponse& response);

/**
 * @brief 反序列化RPC响应
 * @param data 序列化的字符串数据
 * @return RPCResponse 反序列化后的RPCResponse对象
 * 
 * 将字符串形式的响应数据转换回RPCResponse结构体，
 * 用于客户端解析服务器响应。
 */
RPCResponse deserializeResponse(const std::string& data);

#endif // RPC_COMMON_H