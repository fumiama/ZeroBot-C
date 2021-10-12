cmake_minimum_required(VERSION 3.0.0)
project(plugin-test VERSION 1.0)
SET(CMAKE_BUILD_TYPE "Release")

add_library(plugin-test SHARED main.c)
