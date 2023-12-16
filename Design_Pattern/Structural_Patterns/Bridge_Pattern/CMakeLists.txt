file(GLOB_RECURSE files *.cpp)
file(GLOB_RECURSE headers *.h)

add_subdirectory(serviceApi)
add_subdirectory(shape)

add_executable(BridgePatternDemo ${files} ${headers})