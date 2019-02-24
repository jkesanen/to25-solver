add_library(to25-solver "")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_sources(to25-solver
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/board.cpp
        ${CMAKE_CURRENT_LIST_DIR}/board.hpp
        ${CMAKE_CURRENT_LIST_DIR}/resultbase.hpp
        ${CMAKE_CURRENT_LIST_DIR}/solver.hpp
        ${CMAKE_CURRENT_LIST_DIR}/solver.cpp
        ${CMAKE_CURRENT_LIST_DIR}/types.hpp)

target_include_directories(to25-solver
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/.)
