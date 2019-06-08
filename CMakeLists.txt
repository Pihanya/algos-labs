cmake_minimum_required(VERSION 3.13)
project(algos_labs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(lab1)
include_directories(lab2)
include_directories(lab3)
include_directories(lab4)

add_executable(lab1_line_fighting lab1/p3201_mgostev_2025.cpp)
add_executable(lab1_heap_of_stones lab1/p3201_mgostev_1005.cpp)
add_executable(lab1_hyper_junp lab1/p3201_mgostev_1296.cpp)
add_executable(lab1_duones lab1/p3201_mgostev_1155.cpp)
add_executable(lab1_players lab1/p3201_mgostev_1401.cpp)

add_executable(lab2_mean_on_plane lab2/p3201_mgostev_1207.cpp)
add_executable(lab2_in_country_of_dumbass lab2/p3201_mgostev_1604.cpp)
add_executable(lab2_who_guest lab2/p3201_mgostev_1726.cpp)
add_executable(check lab2/lab.cpp)

add_executable(lab3_disk_tree lab3/p3201_mgostev_1067.cpp)
add_executable(lab3_monobilliards lab3/p3201_mgostev_1494.cpp)
add_executable(lab3_white_roads lab3/p3201_mgostev_1628.cpp)

add_executable(lab4_painting lab4/p3201_mgostev_1080.cpp)
add_executable(lab4_network lab4/p3201_mgostev_1160.cpp)
add_executable(lab4_currency_exchange lab4/p3201_mgostev_1162.cpp)
add_executable(lab4_russian_gaslines lab4/p3201_mgostev_1450.cpp)