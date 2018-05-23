cmake_minimum_required(VERSION 3.5)
project(GTK C)

set(CMAKE_C_STANDARD 99)

add_executable(GTK main.c game_board.c logic.c gamecomp.h fifo.c fifo.h)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(GTK ${GTK3_LIBRARIES})
