file(GLOB_RECURSE files *.cpp)
file(GLOB_RECURSE headers *.h)

add_executable(InterpreterPatternDemo ${files} ${headers})