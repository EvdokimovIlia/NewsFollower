cmake_minimum_required(VERSION 3.24.2)

set( PROJECT NewsFollower )

project( ${PROJECT} )

set( SOURCE_EXE main.cpp )

include_directories( configure )

add_executable( ${PROJECT} ${SOURCE_EXE} )

add_definitions( -Wall -Wextra -Werror )

add_subdirectory( configure )

target_link_libraries( ${PROJECT} configure )
