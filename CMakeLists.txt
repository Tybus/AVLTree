cmake_minimum_required(VERSION 2.6)
project(avltree)

add_executable(avltree main.cpp)

install(TARGETS avltree RUNTIME DESTINATION bin)
