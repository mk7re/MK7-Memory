cmake_minimum_required(VERSION 3.15)

project(mk7_memory_verify LANGUAGES CXX)

# ---- C++ settings ----
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- Generate all_headers.hpp ----
file(GLOB_RECURSE MK7_HEADERS
    RELATIVE "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
)

list(SORT MK7_HEADERS)

set(ALL_HEADERS_HPP "${PROJECT_BINARY_DIR}/all_headers.hpp")

option(USE_MK7_NAMESPACE "Enable MK7MEMORY_NAMESPACE=MK7Memory" OFF)

file(WRITE "${ALL_HEADERS_HPP}" "// Auto-generated — do not edit\n\n")

foreach(h ${MK7_HEADERS})
    file(APPEND "${ALL_HEADERS_HPP}" "#include \"${h}\"\n")
endforeach()

# ---- Dummy verification target ----
add_library(header_verify OBJECT verify.cpp)

# ---- Platform defines (Nintendo 3DS / MK7) ----
target_compile_definitions(header_verify PRIVATE
    NNSDK
    GAME_VERSION=VERSION_USA_REV1
)

# ---- Add optional define ----
if(USE_MK7_NAMESPACE)
    target_compile_definitions(header_verify PRIVATE
        MK7MEMORY_NAMESPACE=MK7Memory
    )
endif()

# devkitPro paths
set(DEVKITPRO $ENV{DEVKITPRO})
set(LIBCTRU_INCLUDE "${DEVKITPRO}/libctru/include")

target_include_directories(header_verify PRIVATE
    ${LIBCTRU_INCLUDE}
)

# 32-bit ABI (important for layout verification)
target_compile_options(header_verify PRIVATE -m32)

# Include paths
target_include_directories(header_verify PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}              # for all_headers.hpp
)

target_include_directories(header_verify SYSTEM PRIVATE
    ${PROJECT_SOURCE_DIR}/vendor/sead/include
    ${PROJECT_SOURCE_DIR}/vendor/nnheaders/include
    ${PROJECT_SOURCE_DIR}/vendor/nw4c/include
    ${PROJECT_SOURCE_DIR}/vendor/libc/include
    ${PROJECT_SOURCE_DIR}/vendor/lms/Include
)

# Optional: nicer warnings
target_compile_options(header_verify PRIVATE
    -Wall -Wextra
)
