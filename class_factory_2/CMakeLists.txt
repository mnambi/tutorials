cmake_minimum_required(VERSION 2.8.7)
project(ClassFactory)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    src/main.cpp
    src/base.cpp
    src/derived1.cpp
    src/derived2.cpp
    src/factory.cpp)

set(HEADERS
    src/base.h
    src/derived1.h
    src/derived2.h
    src/factory.h)

add_executable(classFactory
               ${SOURCES}
               ${HEADERS}
               )
