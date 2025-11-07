/**
 * @file RPCCommon.cpp
 * @brief RPC框架公共组件实现文件
 * 
 * 这个文件实现了RPC框架中客户端和服务器共享的序列化和反序列化功能，
 * 提供了请求和响应数据在网络传输前后的转换功能。
 * 使用简单的基于分隔符的序列化协议，确保数据能够正确地在网络上传输。
 */
#include "RPCCommon.h"
#include <sstream>   // 用于字符串流操作
#include <algorithm> // 用于字符串操作算法

/**
 * @brief 序列化RPC请求
 * @param request RPCRequest结构体对象
 * @return std::string 序列化后的字符串
 * 
 * 使用简单的基于分隔符的格式序列化RPC请求，格式为：
 * REQUEST:request_id:method_name:arg1,arg2,arg3
 * 这种格式易于解析，同时保持了数据的结构化。
 */
std::string serializeRequest(const RPCRequest& request) {
    std::stringstream ss;  // 创建字符串流用于构建序列化结果
    
    // 写入请求类型标识、请求ID和方法名
    ss << "REQUEST:" << request.request_id << ":" << request.method_name << ":";
    
    // 写入参数列表，用逗号分隔
    for (size_t i = 0; i < request.arguments.size(); ++i) {
        ss << request.arguments[i];
        if (i < request.arguments.size() - 1) {
            ss << ","; // 为除最后一个参数外的所有参数添加逗号分隔符
        }
    }
    
    return ss.str(); // 返回序列化的字符串
}

/**
 * @brief 反序列化RPC请求
 * @param data 序列化的字符串数据
 * @return RPCRequest 反序列化后的RPCRequest对象
 * 
 * 从序列化的字符串中解析出RPC请求的各个字段，
 * 包括请求ID、方法名和参数列表。
 * 如果解析失败，返回一个空的RPCRequest对象。
 */
RPCRequest deserializeRequest(const std::string& data) {
    RPCRequest request;  // 创建请求对象用于存储解析结果
    
    // 检查数据格式是否正确，必须以"REQUEST:"开头
    size_t pos = data.find(":");
    if (pos == std::string::npos || data.substr(0, pos) != "REQUEST") {
        return request;  // 格式错误，返回空对象
    }
    
    // 解析请求ID
    size_t prev_pos = pos + 1;
    pos = data.find(":", prev_pos);
    if (pos != std::string::npos) {
        request.request_id = std::stoi(data.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + 1;
    }
    
    // 解析方法名
    pos = data.find(":", prev_pos);
    if (pos != std::string::npos) {
        request.method_name = data.substr(prev_pos, pos - prev_pos);
        prev_pos = pos + 1;
    }
    
    // 解析参数列表
    std::string args_str = data.substr(prev_pos);  // 获取参数部分
    std::stringstream ss(args_str);                // 创建字符串流
    std::string arg;
    
    // 用逗号分隔参数并添加到参数向量中
    while (std::getline(ss, arg, ',')) {
        request.arguments.push_back(arg);
    }
    
    return request;  // 返回解析后的请求对象
}

/**
 * @brief 序列化RPC响应
 * @param response RPCResponse结构体对象
 * @return std::string 序列化后的字符串
 * 
 * 使用简单的基于分隔符的格式序列化RPC响应，格式为：
 * RESPONSE:request_id:success_flag:result/error_message
 * 根据成功标志，最后一个字段可能是执行结果或错误信息。
 */
std::string serializeResponse(const RPCResponse& response) {
    std::stringstream ss;  // 创建字符串流用于构建序列化结果
    
    // 写入响应类型标识、请求ID和成功标志（1表示成功，0表示失败）
    ss << "RESPONSE:" << response.request_id << ":" << (response.success ? "1" : "0") << ":";
    
    // 根据成功标志写入结果或错误信息
    if (response.success) {
        ss << response.result;           // 成功时写入结果
    } else {
        ss << response.error_message;    // 失败时写入错误信息
    }
    
    return ss.str();  // 返回序列化的字符串
}

/**
 * @brief 反序列化RPC响应
 * @param data 序列化的字符串数据
 * @return RPCResponse 反序列化后的RPCResponse对象
 * 
 * 从序列化的字符串中解析出RPC响应的各个字段，
 * 包括请求ID、成功标志、结果或错误信息。
 * 如果解析失败，返回一个空的RPCResponse对象。
 */
RPCResponse deserializeResponse(const std::string& data) {
    RPCResponse response;  // 创建响应对象用于存储解析结果
    
    // 检查数据格式是否正确，必须以"RESPONSE:"开头
    size_t pos = data.find(":");
    if (pos == std::string::npos || data.substr(0, pos) != "RESPONSE") {
        return response;  // 格式错误，返回空对象
    }
    
    // 解析请求ID
    size_t prev_pos = pos + 1;
    pos = data.find(":", prev_pos);
    if (pos != std::string::npos) {
        response.request_id = std::stoi(data.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + 1;
    }
    
    // 解析成功标志（1表示成功，0表示失败）
    pos = data.find(":", prev_pos);
    if (pos != std::string::npos) {
        response.success = (data.substr(prev_pos, pos - prev_pos) == "1");
        prev_pos = pos + 1;
    }
    
    // 根据成功标志解析结果或错误信息
    if (response.success) {
        response.result = data.substr(prev_pos);           // 成功时解析结果
    } else {
        response.error_message = data.substr(prev_pos);    // 失败时解析错误信息
    }
    
    return response;  // 返回解析后的响应对象
}