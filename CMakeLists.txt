cmake_minimum_required(VERSION 3.19)
project(seanet C)

set(CMAKE_C_STANDARD 11)

add_executable(seanet main.c task_queue.c task_queue.h task.c task.h thread.c thread.h)
target_link_libraries(seanet pthread)
