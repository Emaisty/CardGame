cmake_minimum_required(VERSION 3.21)
project(CardGame)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS Headers)
set(SOURCES Sources)

include_directories(${HEADERS})
include_directories(${SOURCES})

set(
        SOURCE_FILES
        ${HEADERS}/Card.h
        ${SOURCES}/Card.cpp
        main.cpp
)

add_executable(CardGame ${SOURCE_FILES})
