cmake_minimum_required(VERSION 2.8.7)
project(Sockets)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    src/udp_server.cpp
    src/udp_client.cpp
    src/server_app.cpp
    src/client_app.cpp
    )

set(HEADERS
    src/udp_server.h
    src/udp_client.h
    )

add_executable(udp_server
               src/udp_server.cpp
               src/udp_server.h
               src/server_app
               )

add_executable(udp_client
              src/udp_client.cpp
              src/udp_client.h
              src/client_app.cpp
              )
