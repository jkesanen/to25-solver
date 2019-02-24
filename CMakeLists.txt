CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

project(to25)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(src/CMakeLists.txt)

add_subdirectory(apps)

#target_compile_options(to25 PUBLIC
                           # clang/GCC warnings
#                           $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
#                                -Wall -Wextra -Werror -Wconversion -Wsign-conversion >)
                           # MSVC warnings
                           #$<$<CXX_COMPILER_ID:MSVC>:
                           #     "/W4 /WX" >)
