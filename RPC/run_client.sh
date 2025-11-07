#!/bin/bash

# RPC客户端启动脚本
# 直接使用g++编译并运行客户端代码

echo "编译并启动RPC客户端..."

# 确保build目录存在
mkdir -p build

# 编译客户端
CLIENT_SRC="examples/CalculatorClientExample.cpp client/RPCClient.cpp include/RPCCommon.cpp"
CLIENT_OUT="./build/calculator_client"

g++ -std=c++11 -Iinclude $CLIENT_SRC -o $CLIENT_OUT

if [ $? -eq 0 ]; then
    echo "编译成功！"
    echo "启动客户端..."
    ./$CLIENT_OUT
else
    echo "编译失败，请检查代码。"
    exit 1
fi