cmake_minimum_required(VERSION 2.8.7)
project(ClassFactory)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    src/base.cpp
    src/factory.cpp
    src/derived1.cpp
    src/derived2.cpp
    src/main.cpp
    )

set(HEADERS
    src/base.h
    src/factory.h
    src/derived1.h
    src/derived2.h
    )

add_executable(classFactory
               ${SOURCES}
               ${HEADERS}
               )
