cmake_minimum_required(VERSION 3.29 FATAL_ERROR)

project(leetcode-cpp CXX)

find_package(Catch2 3 REQUIRED)

enable_testing()

include(cmake/functions.cmake)

# Включаем C++20 во всём проекте
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Экспортируем команды для использования с VSCode C++ IntelliSense
# См. https://stackoverflow.com/questions/54671883/how-can-i-set-up-c-c-intellisense-for-a-cmake-project-in-vs-code
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(26_remove_duplicates)
add_subdirectory(27_remove_element)
add_subdirectory(45_jump_game_2)
add_subdirectory(55_jump_game)
add_subdirectory(80_remove_duplicates)
add_subdirectory(88_merge_sorted_array)
add_subdirectory(121_best_time_to_buy_and_sell)
add_subdirectory(122_best_time_to_buy_and_sell_v2)
add_subdirectory(134_gas_station)
add_subdirectory(150_reverse_polish)
add_subdirectory(169_majority_element)
add_subdirectory(189_rotate_array)
add_subdirectory(274_h_index)
