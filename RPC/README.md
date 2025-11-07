# RPC项目

这是一个基于C++实现的简单RPC（远程过程调用）系统示例。

## 项目结构

```
RPC/
├── build/               # 构建目录（编译产物）
│   ├── bin/             # 可执行文件输出目录
│   └── lib/             # 库文件输出目录
├── include/             # 头文件目录
├── client/              # 客户端代码
├── server/              # 服务器代码
├── examples/            # 示例代码
├── CMakeLists.txt       # CMake构建配置
├── run_server.sh        # 服务器启动脚本
└── run_client.sh        # 客户端启动脚本
```

## 构建说明

### 编译项目

```bash
mkdir -p build && cd build && cmake .. && make
```

编译后的文件将输出到：
- 可执行文件：`build/bin/`
- 库文件：`build/lib/`

### 运行示例

#### 启动服务器

```bash
# 方法1：使用启动脚本（推荐）
./run_server.sh

# 方法2：直接运行可执行文件
./build/bin/calculator_server
```

#### 启动客户端

```bash
# 方法1：使用启动脚本（推荐）
./run_client.sh

# 方法2：直接运行可执行文件
./build/bin/calculator_client
```

## 优势说明

1. **源代码目录整洁**：所有构建产物都放在`build/`目录中，不会污染源代码目录
2. **结构化输出**：可执行文件和库文件分别输出到`bin/`和`lib/`子目录
3. **易于使用**：提供启动脚本，用户无需记忆复杂路径
4. **便于清理**：需要清理时只需删除`build/`目录
5. **跨平台兼容性**：支持不同构建配置（Debug/Release）

## 注意事项

- 确保系统已安装CMake 3.10或更高版本
- 确保使用C++11兼容的编译器
- 运行前请确保服务器已启动