cmake_minimum_required(VERSION 3.15)

if(NOT CMAKE_TOOLCHAIN_FILE)
    if(DEFINED ENV{DEVKITPRO} AND EXISTS "$ENV{DEVKITPRO}/cmake/3DS.cmake")
        set(CMAKE_TOOLCHAIN_FILE "$ENV{DEVKITPRO}/cmake/3DS.cmake" CACHE FILEPATH "3DS Toolchain file")
    else ()
        message(FATAL_ERROR "ENV DEVKITPRO not set")
    endif()
endif()


cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME ProjectName)

# rename your project here - default is dir name
set(3DS_APP_NAME ${ProjectName})

project(${3DS_APP_NAME} C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# lower optimization for debug builds to fix <optimized out> variables
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

add_executable(${3DS_APP_NAME} src/main.cpp)

target_include_directories(${3DS_APP_NAME} PRIVATE include $ENV{DEVKITPRO}/libctru/include)
target_link_libraries(${3DS_APP_NAME} PRIVATE ctru m)

if(COMMAND ctr_create_3dsx)
    ctr_generate_smdh(
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${3DS_APP_NAME}.smdh"
        NAME "${3DS_APP_NAME}"
        DESCRIPTION "template for 3ds development"
        AUTHOR "slyk26"
    )

    ctr_create_3dsx(${3DS_APP_NAME}
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${3DS_APP_NAME}.3dsx"
        SMDH "${CMAKE_CURRENT_BINARY_DIR}/${3DS_APP_NAME}.smdh"
    )

endif()
