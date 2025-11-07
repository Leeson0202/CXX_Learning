#include "../server/RPCServer.h"
#include "../include/CalculatorServiceImpl.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    // 创建RPC服务器，监听8080端口
    RPCServer server(8080);
    
    // 创建计算器服务实例
    CalculatorServiceImpl calculator;
    
    // 注册add方法
    server.registerMethod("add", [&calculator](const std::vector<std::string>& args) -> std::string {
        if (args.size() != 2) {
            return "Error: add requires exactly 2 arguments";
        }
        
        try {
            long long a = std::stoll(args[0]);
            long long b = std::stoll(args[1]);
            long long result = calculator.add(a, b);
            return std::to_string(result);
        } catch (const std::exception& e) {
            return std::string("Error: ") + e.what();
        }
    });
    
    // 注册subtract方法
    server.registerMethod("subtract", [&calculator](const std::vector<std::string>& args) -> std::string {
        if (args.size() != 2) {
            return "Error: subtract requires exactly 2 arguments";
        }
        
        try {
            long long a = std::stoll(args[0]);
            long long b = std::stoll(args[1]);
            long long result = calculator.subtract(a, b);
            return std::to_string(result);
        } catch (const std::exception& e) {
            return std::string("Error: ") + e.what();
        }
    });
    
    // 注册multiply方法
    server.registerMethod("multiply", [&calculator](const std::vector<std::string>& args) -> std::string {
        if (args.size() != 2) {
            return "Error: multiply requires exactly 2 arguments";
        }
        
        try {
            long long a = std::stoll(args[0]);
            long long b = std::stoll(args[1]);
            long long result = calculator.multiply(a, b);
            return std::to_string(result);
        } catch (const std::exception& e) {
            return std::string("Error: ") + e.what();
        }
    });
    
    // 注册divide方法
    server.registerMethod("divide", [&calculator](const std::vector<std::string>& args) -> std::string {
        if (args.size() != 2) {
            return "Error: divide requires exactly 2 arguments";
        }
        
        try {
            long long a = std::stoll(args[0]);
            long long b = std::stoll(args[1]);
            double result = calculator.divide(a, b);
            std::stringstream ss;
            ss << result;
            return ss.str();
        } catch (const std::exception& e) {
            return std::string("Error: ") + e.what();
        }
    });
    
    // 启动服务器
    if (server.start()) {
        std::cout << "Calculator RPC Server is running. Press Ctrl+C to stop." << std::endl;
        
        // 等待用户输入以退出
        std::string input;
        std::getline(std::cin, input);
        
        // 停止服务器
        server.stop();
    } else {
        std::cerr << "Failed to start RPC server" << std::endl;
        return 1;
    }
    
    return 0;
}