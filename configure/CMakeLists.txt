cmake_minimum_required(VERSION 3.24.2)

project( configure )

set( SOURCE_LIB configure.cpp )

add_library( configure SHARED ${SOURCE_LIB} )
