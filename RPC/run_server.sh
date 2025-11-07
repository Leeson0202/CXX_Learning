#!/bin/bash

# RPC服务器启动脚本
# 直接使用g++编译并运行服务器代码

echo "编译并启动RPC服务器..."

# 确保build目录存在
mkdir -p build

# 编译服务器
SERVER_SRC="examples/CalculatorServerExample.cpp server/RPCServer.cpp include/RPCCommon.cpp"
SERVER_OUT="./build/calculator_server"

g++ -std=c++11 -Iinclude $SERVER_SRC -o $SERVER_OUT

if [ $? -eq 0 ]; then
    echo "编译成功！"
    echo "启动服务器..."
    ./$SERVER_OUT
else
    echo "编译失败，请检查代码。"
    exit 1
fi