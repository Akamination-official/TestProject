cmake_minimum_required(VERSION 3.16)
project(TupleDispatcher LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(dispatcher SHARED
    class.cpp
    dispatcher.cpp
)

target_include_directories(dispatcher PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(dispatcher PRIVATE DISPATCHER_EXPORTS CLASS_EXPORTS)

add_executable(test
    main.cpp
)

target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test PRIVATE dispatcher)