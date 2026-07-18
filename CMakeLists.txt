cmake_minimum_required(VERSION 3.16)

project(cpp_stl_hot100 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(training_options INTERFACE)

if(MSVC)
    target_compile_options(training_options INTERFACE /W4 /permissive-)
else()
    target_compile_options(training_options INTERFACE -Wall -Wextra -Wpedantic)
endif()

function(add_exercise target source)
    add_executable(${target} ${source})
    target_link_libraries(${target} PRIVATE training_options)
endfunction()

add_exercise(hash_basics day01/01_hash_table/0000_unordered_map_basics.cpp)
add_exercise(lc0049 day01/01_hash_table/0049_group_anagrams.cpp)
add_exercise(lc0128 day01/01_hash_table/0128_longest_consecutive_sequence.cpp)
add_exercise(lc0011 day01/02_two_pointers/0011_container_with_most_water.cpp)
add_exercise(lc0015 day01/02_two_pointers/0015_three_sum.cpp)
add_exercise(lc0003 day01/03_sliding_window/0003_longest_substring.cpp)
add_exercise(lc0438 day01/03_sliding_window/0438_find_all_anagrams.cpp)
add_exercise(lc0560 day01/04_prefix_sum/0560_subarray_sum_equals_k.cpp)
