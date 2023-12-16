file(GLOB_RECURSE files *.cpp)
file(GLOB_RECURSE headers *.h)

add_subdirectory(color)
add_subdirectory(factory)
add_subdirectory(shape)

add_executable(AbstractFactoryDemo ${files} ${headers})