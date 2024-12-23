cmake_minimum_required(VERSION 3.26)
project(Sem3Task6)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sem3Task6 main.cpp
        Func.cpp
        Func.h
)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(MyTests test.cpp
        Func.cpp
        Func.h
)

target_link_libraries(MyTests gtest gtest_main)
add_test(NAME MyTests COMMAND MyTests)

add_custom_target(run_tests
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        DEPENDS MyTests
)

add_dependencies(Sem3Task6 run_tests)
