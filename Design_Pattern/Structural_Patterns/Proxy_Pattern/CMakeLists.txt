file(GLOB_RECURSE files *.cpp)
file(GLOB_RECURSE headers *.h)

add_subdirectory(image)

add_executable(ProxyPatternDemo ${files} ${headers})