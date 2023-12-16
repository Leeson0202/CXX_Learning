# 遍历项目根目录下所有的 .cpp 文件
file(GLOB_RECURSE files ./*.cpp)
file(GLOB_RECURSE headers *.h)


add_subdirectory(shape)

add_executable(ShapeFactoryDemo ${files} ${headers})