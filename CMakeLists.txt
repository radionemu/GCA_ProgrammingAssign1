cmake_minimum_required(VERSION 3.10)
project(GLA)

set(CMAKE_CXX_STANDARD 11)

include_directories(
    general
    externals/glm-0.9.9.8
    externals/lodepng
    .
)

add_executable(GLA
    Sample_main.cpp
    general/resolution.cpp
    general/resolution.hpp
    )
target_link_libraries(GLA -lOpenGL32 -lfreeGLUT -lglew32)