cmake_minimum_required(VERSION 3.15)

if(NOT CMAKE_TOOLCHAIN_FILE)
    if(DEFINED ENV{DEVKITPRO} AND EXISTS "$ENV{DEVKITPRO}/cmake/3DS.cmake")
        set(CMAKE_TOOLCHAIN_FILE "$ENV{DEVKITPRO}/cmake/3DS.cmake" CACHE FILEPATH "3DS Toolchain file")
    else ()
        message(FATAL_ERROR "ENV DEVKITPRO not set")
    endif()
endif()


cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME ProjectName)
string(REPLACE " " "_" ProjectId "${ProjectName}")

set(3DS_APP_NAME ${ProjectName})

project(${ProjectId} C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# lower optimization for debug builds to fix <optimized out> variables
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

add_executable(${ProjectId} src/main.cpp)

target_include_directories(${ProjectId} PRIVATE include $ENV{DEVKITPRO}/libctru/include)
target_link_libraries(${ProjectId} PRIVATE ctru m)

if(COMMAND ctr_create_3dsx)
    ctr_generate_smdh(
            OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${ProjectId}.smdh"
            # default project name - can be replaced
            NAME "${ProjectName}"
            DESCRIPTION "template for 3ds development"
            AUTHOR "slyk26"
    )

    ctr_create_3dsx(${ProjectId}
            OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${ProjectId}.3dsx"
            SMDH "${CMAKE_CURRENT_BINARY_DIR}/${ProjectId}.smdh"
    )

endif()
