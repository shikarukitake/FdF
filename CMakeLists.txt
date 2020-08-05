cmake_minimum_required(VERSION 3.16)
project(FdF C)

set(CMAKE_C_STANDARD 11)

include_directories(general/includes)
include_directories(general/libftprintf/includes)
include_directories(minilibx/)

# Libft
file(GLOB_RECURSE LIBFT_FILES "${PROJECT_SOURCE_DIR}/general/libftprintf/srcs/*.c")
set(LIBFT_FILES ${LIBFT_FILES} ${LIBFT_ADD_FILES})
add_library(ftprintf STATIC ${LIBFT_FILES})


# FdF
add_executable(FdF general/srcs/main.c general/includes/fdf.h general/srcs/service.c general/srcs/read_file.c general/srcs/draw.c)
target_link_libraries(FdF ${PROJECT_BINARY_DIR}/libftprintf.a)
add_dependencies(FdF ftprintf)

add_custom_target(my_test COMMAND make -C ${FdF_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})