CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

project(to25_solver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND SOURCES
    board.cpp
    board.hpp
    main.cpp
    solver.cpp
    solver.hpp
    types.hpp)

add_executable(to25_solver
    ${SOURCES})

target_compile_options(to25_solver PRIVATE
                           # clang/GCC warnings
                           $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
                                -Wall -Wextra -Werror -Wconversion -Wsign-conversion >)
                           # MSVC warnings
                           #$<$<CXX_COMPILER_ID:MSVC>:
                           #     "/W4 /WX" >)
