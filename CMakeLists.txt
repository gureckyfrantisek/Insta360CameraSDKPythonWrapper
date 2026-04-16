cmake_minimum_required(VERSION 3.15)
project(pybind_example)

include(FetchContent)

FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v3.0.3
)

FetchContent_MakeAvailable(pybind11)

pybind11_add_module(module_name wrapper.cpp)