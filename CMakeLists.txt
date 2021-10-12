cmake_minimum_required(VERSION 3.0.0)
project(a VERSION 2.0)
SET(CMAKE_BUILD_TYPE "Release")

add_library(plugin-test SHARED main.c)
