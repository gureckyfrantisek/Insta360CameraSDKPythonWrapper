cmake_minimum_required(VERSION 3.15)
project(Insta360SDKWrapper)

include(FetchContent)

FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v3.0.3
)

FetchContent_MakeAvailable(pybind11)

# SDK paths
set(SDK_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/sdk/include)
set(SDK_LIB_DIR ${CMAKE_SOURCE_DIR}/sdk/lib)

find_library(CAMERA_SDK_LIB
    NAMES CameraSDK
    PATHS ${SDK_LIB_DIR}
    NO_DEFAULT_PATH
)

# Output module
pybind11_add_module(camerasdk wrapper.cpp)

# Headers target
target_include_directories(camerasdk PRIVATE
    ${SDK_INCLUDE_DIR}
)

# Libraries target
target_link_directories(camerasdk PRIVATE
    ${SDK_LIB_DIR}
)

target_link_libraries(camerasdk PRIVATE
    pybind11::module
    ${CAMERA_SDK_LIB}
)
