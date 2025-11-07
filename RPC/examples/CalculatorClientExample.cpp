#include "../client/RPCClient.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    // 创建RPC客户端，连接到本地服务器的8080端口
    RPCClient client("127.0.0.1", 8080);
    
    // 连接服务器
    if (!client.connect()) {
        std::cerr << "Failed to connect to server. Make sure the server is running." << std::endl;
        return 1;
    }
    
    std::cout << "Calculator RPC Client started. Enter 'exit' to quit." << std::endl;
    
    std::string operation;
    while (true) {
        std::cout << "\n\033[1;36mAvailable operations: add, subtract, multiply, divide\033[0m" << std::endl;
        std::cout << "Enter operation (or 'exit'): ";
        std::cin >> operation;
        
        if (operation == "exit") {
            break;
        }
        
        long long a, b;
        std::cout << "Enter first number: ";
        std::cin >> a;
        std::cout << "Enter second number: ";
        std::cin >> b;
        
        // 准备参数
        std::vector<std::string> args;
        args.push_back(std::to_string(a));
        args.push_back(std::to_string(b));
        
        // 调用RPC方法
        std::string result = client.callMethod(operation, args);
        
        // 显示结果
        std::cout << "Result: " << result << std::endl;
    }
    
    // 断开连接
    client.disconnect();
    std::cout << "Client disconnected." << std::endl;
    
    return 0;
}