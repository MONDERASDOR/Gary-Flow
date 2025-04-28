cmake_minimum_required(VERSION 3.10)
project(GaryFlow C)

set(CMAKE_C_STANDARD 11)

add_executable(garyflow core/main.c)

if (WIN32)
    target_compile_definitions(garyflow PRIVATE _WIN32_WINNT=0x0601)
    target_link_libraries(garyflow ws2_32)
endif()
