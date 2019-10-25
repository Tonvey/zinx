cmake_minimum_required(VERSION 3.10)
project(LibZinx)
set(CMAKE_CXX_STANDARD 11)
file(GLOB srcs *.c*)
file(GLOB headers *.h)

include_directories(./)

add_library(LibZinxShared SHARED ${srcs})
add_library(LibZinxStatic STATIC ${srcs})

set_target_properties(LibZinxShared PROPERTIES OUTPUT_NAME zinx)
set_target_properties(LibZinxStatic PROPERTIES OUTPUT_NAME zinx)

add_subdirectory(./samples)

IF (NOT CMAKE_INSTALL_PREFIX)
    SET(CMAKE_INSTALL_PREFIX "/usr/local/"
        CACHE PATH "Install path prefix" FORCE)
ELSE (NOT CMAKE_INSTALL_PREFIX)
    MESSAGE("CMAKE_INSTALL_PREFIX already set to: ${CMAKE_INSTALL_PREFIX}")
ENDIF (NOT CMAKE_INSTALL_PREFIX)

install(TARGETS LibZinxShared LibZinxStatic
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
install(FILES ${headers} DESTINATION include)
