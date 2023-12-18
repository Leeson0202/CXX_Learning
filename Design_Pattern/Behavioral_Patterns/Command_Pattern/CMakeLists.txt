file(GLOB_RECURSE files *.cpp)
file(GLOB_RECURSE headers *.h)

#add_subdirectory(order)

add_executable(CommandPatternDemo ${files} ${headers})