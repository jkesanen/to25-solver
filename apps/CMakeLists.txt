project(to25)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND SOURCES
    main.cpp
    results.cpp
    results.hpp)

add_executable(to25
    ${SOURCES})

target_link_libraries(to25 to25-solver)
