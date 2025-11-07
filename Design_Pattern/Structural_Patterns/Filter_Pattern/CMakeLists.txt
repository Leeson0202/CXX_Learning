# 直接列出源文件而不使用GLOB_RECURSE，避免收集到不需要的文件
set(SOURCES
    FilterPatternDemo.cpp
    Person.cpp
)

set(HEADERS
    Person.h
)

# 添加criteria子目录
add_subdirectory(criteria)

# 创建可执行文件，使用全局设置的输出目录
add_executable(FilterPatternDemo ${SOURCES} ${HEADERS})

# 确保使用全局设置的输出目录
set_target_properties(FilterPatternDemo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)