cmake_minimum_required(VERSION 3.20.0)
project(base64enc
    VERSION 1.0
    LANGUAGES C)
add_executable(${PROJECT_NAME}
    src/base64enc.c
    src/common.c
    src/encode.c
    src/decode.c)

target_include_directories(${PROJECT_NAME} PUBLIC include)