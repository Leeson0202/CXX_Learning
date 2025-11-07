cmake_minimum_required(VERSION 3.10)
project(RPCDemo)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 优化输出目录配置
# 确保所有构建产物都放在build目录下
# 这样可以保持源代码目录的整洁
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 为不同配置设置不同的输出目录（Debug/Release）
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/lib)
endforeach(OUTPUTCONFIG)

# 包含头文件目录
include_directories(include)

# RPC核心库源文件
set(RPC_CORE_SOURCES
    include/RPCCommon.cpp
)

# 服务器源文件
set(RPC_SERVER_SOURCES
    server/RPCServer.cpp
)

# 客户端源文件
set(RPC_CLIENT_SOURCES
    client/RPCClient.cpp
)

# 创建RPC核心库
add_library(rpc_core ${RPC_CORE_SOURCES})

# 创建RPC服务器库
add_library(rpc_server ${RPC_SERVER_SOURCES})
target_link_libraries(rpc_server rpc_core)

# 创建RPC客户端库
add_library(rpc_client ${RPC_CLIENT_SOURCES})
target_link_libraries(rpc_client rpc_core)

# 创建服务器示例
add_executable(calculator_server examples/CalculatorServerExample.cpp)
target_link_libraries(calculator_server rpc_server rpc_core)

# 创建客户端示例
add_executable(calculator_client examples/CalculatorClientExample.cpp)
target_link_libraries(calculator_client rpc_client rpc_core)

# 添加安装规则
install(TARGETS calculator_server calculator_client
    RUNTIME DESTINATION bin
)

install(TARGETS rpc_core rpc_server rpc_client
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include/RPC)