cmake_minimum_required(VERSION 3.15.0)

project(clangex)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CLANG_DIR "/Users/gnimuc/.julia/artifacts/6c7a3feab6522aaf3177294226d990601674698a")
set(LLVM_DIR "/Users/gnimuc/.julia/artifacts/3573623adf6de1dfee72be3f6edc6400772b8f76")

if(EXISTS ${CLANG_DIR})
    message(STATUS "Found Clang directory: " ${CLANG_DIR})
else()
    message(FATAL_ERROR "Cannot find Clang directory. You may need to install `Clang_jll`.")
endif()

if(EXISTS ${LLVM_DIR})
    message(STATUS "Found LLVM directory: " ${LLVM_DIR})
else()
    message(FATAL_ERROR "Cannot find LLVM directory. You may need to install `LLVM_full_jll`.")
endif()

# if(LLVM_SOURCE_PREFIX)
#     set(LLVM_SOURCE_DIR "${LLVM_SOURCE_PREFIX}")
#     message(STATUS "Found LLVM_SOURCE_DIR: " ${LLVM_SOURCE_DIR})
# else()
#     message(FATAL_ERROR "Please set `LLVM_SOURCE_PREFIX`")
# endif()

find_library(ClangCPP NAMES clang-cpp HINTS "${CLANG_DIR}/lib")
message(STATUS "Found Clang: ${ClangCPP}")

find_library(LLVM NAMES LLVM HINTS "${LLVM_DIR}/lib")
message(STATUS "Found LLVM: ${LLVM}")

add_library(clangex SHARED)

target_sources(clangex PRIVATE src/libclangex.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SKIP_RPATH ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fno-rtti")

target_include_directories(clangex PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CLANG_DIR}/include>
    $<BUILD_INTERFACE:${LLVM_DIR}/include>
    # $<BUILD_INTERFACE:${LLVM_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)

set(PUB_HEADERS_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_property(TARGET clangex APPEND PROPERTY
    PUBLIC_HEADER ${PUB_HEADERS_PREFIX}/libclangex.h
                  )

target_link_libraries(clangex ${ClangCPP} ${LLVM})

install(TARGETS clangex
        EXPORT clangex-targets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        INCLUDES DESTINATION include
        PUBLIC_HEADER DESTINATION include)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json DESTINATION share)
