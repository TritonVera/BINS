cmake_minimum_required(VERSION 3.5)

project(BINS_Alg LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(BOOST REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(BINS_Alg main.cpp converters.cpp algorithm.cpp converters.h algorithm.h)
