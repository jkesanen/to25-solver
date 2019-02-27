CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

if(MSVC)
    # To overcome LNK2038 - mismatch detected for 'RuntimeLibrary'
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    message(STATUS "Forcing gtest_force_shared_crt ${gtest_force_shared_crt} in ${CMAKE_CURRENT_LIST_FILE}")
endif()

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.8.1
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} gtest gtest_main to25-solver)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

set(TEST_SOURCES
    boardtests.cpp
    solvertests.cpp)

package_add_test(unittests ${TEST_SOURCES})
