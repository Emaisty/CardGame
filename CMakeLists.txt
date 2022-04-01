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
        ${HEADERS}/Spell_card.h
        ${HEADERS}/Combat_card.h
        ${HEADERS}/Hero_buff_card.h
        ${HEADERS}/Player.h

        ${SOURCES}/Card.cpp
        ${SOURCES}/Spell_card.cpp
        ${SOURCES}/Combat_card.cpp
        ${SOURCES}/Hero_buff_card.cpp
        ${SOURCES}/Player.cpp

        main.cpp)

add_executable(CardGame ${SOURCE_FILES})
