cmake_minimum_required ( VERSION 3.5.1 )
project ( Tetris )

cmake_policy ( SET CMP0011 NEW )
cmake_policy ( SET CMP0003 OLD )

OPTION ( WITH_DEBUG_MODE "Build with debug mode" ON )

if ( NOT UNIX )
	message ( FATAL_ERROR "Not Unix" )
endif ()

# The version number
set ( Tetris_VERSION_MAJOR 1 )
set ( Tetris_VERSION_MINOR 0 )

set ( CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build )

include_directories ( /control/headers /model/headers /view/headers )
set ( SOURCES /control/src /model/src /view/src )

add_executable ( Tetris ${SOURCES} )
