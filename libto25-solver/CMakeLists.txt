CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

add_library(to25-solver "")

set_target_properties(to25-solver PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)

target_compile_options(to25-solver
    PUBLIC
        # MSVC compile options
        $<$<CXX_COMPILER_ID:MSVC>:
            "/W4" "/WX" >
        # Clang & GCC compile options
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
            "-Wall" "-Wextra" "-Werror" "-Wconversion" "-Wsign-conversion" "$<$<CXX_COMPILER_ID:Clang>:-stdlib=libc++" > >)

target_sources(to25-solver
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/board.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/solver.cpp

        ${CMAKE_CURRENT_LIST_DIR}/include/to25-solver/board.hpp
        ${CMAKE_CURRENT_LIST_DIR}/include/to25-solver/resultbase.hpp
        ${CMAKE_CURRENT_LIST_DIR}/include/to25-solver/solver.hpp
        ${CMAKE_CURRENT_LIST_DIR}/include/to25-solver/types.hpp)

target_include_directories(to25-solver
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include/to25-solver)
