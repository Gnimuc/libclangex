cmake_minimum_required(VERSION 3.15.0)

project(clangex)

set(LLVM_ARTIFACTS_VER "v9.0.1+1")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(JULIA_ARTIFACTS_DIR)
    set(JULIA_CLANG_ARTIFACTS_DIR "${JULIA_ARTIFACTS_DIR}/0fc3ff57692101a729211b7033bb4f22f07ae4a2")
    if(EXISTS "${JULIA_CLANG_ARTIFACTS_DIR}")
        message(STATUS "Found JULIA_CLANG_ARTIFACTS_DIR: " ${JULIA_CLANG_ARTIFACTS_DIR})
    else()
        message(FATAL_ERROR "Cannot find `Clang_jll`'s artifact directory. Please install the correct version of `Clang_jll${LLVM_ARTIFACTS_VER}`.")
    endif()

    set(JULIA_LLVM_ARTIFACTS_DIR "${JULIA_ARTIFACTS_DIR}/a7b0b6ce414ae2c7a1a805d071b1efa63b9db122")
    if(EXISTS "${JULIA_LLVM_ARTIFACTS_DIR}")
        message(STATUS "Found JULIA_LLVM_ARTIFACTS_DIR: " ${JULIA_LLVM_ARTIFACTS_DIR})
    else()
        message(FATAL_ERROR "Cannot find `LLVM_jll`'s artifact directory. Please install the correct version of `LLVM_jll${LLVM_ARTIFACTS_VER}`.")
    endif()
else()
    message(FATAL_ERROR "Please set `JULIA_ARTIFACTS_DIR`.")
endif()

if(LLVM_SOURCE_PREFIX)
    set(LLVM_SOURCE_DIR "${LLVM_SOURCE_PREFIX}")
    message(STATUS "Found LLVM_SOURCE_DIR: " ${LLVM_SOURCE_DIR})
else()
    message(FATAL_ERROR "Please set `LLVM_SOURCE_PREFIX`")
endif()

find_library(LibClang NAMES clang HINTS "${JULIA_CLANG_ARTIFACTS_DIR}/lib")
message(STATUS "Found libClang: ${LibClang}")

find_library(ClangCPP NAMES clang-cpp HINTS "${JULIA_CLANG_ARTIFACTS_DIR}/lib")
message(STATUS "Found Clang: ${ClangCPP}")

find_library(LLVM NAMES LLVM HINTS "${JULIA_LLVM_ARTIFACTS_DIR}/lib")
message(STATUS "Found LLVM: ${LLVM}")


add_library(clangex SHARED)

target_sources(clangex PRIVATE src/libclangex.cpp)
target_sources(clangex PRIVATE src/CXCompilerInvocation.cpp)
target_sources(clangex PRIVATE src/CXCompilerInstance.cpp)
target_sources(clangex PRIVATE src/CXCodeGenOptions.cpp)
target_sources(clangex PRIVATE src/CXDiagnosticOptions.cpp)
target_sources(clangex PRIVATE src/CXDiagnostic.cpp)
target_sources(clangex PRIVATE src/CXFileManager.cpp)
target_sources(clangex PRIVATE src/CXTriple.cpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SKIP_RPATH ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fno-rtti")

target_include_directories(clangex PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${JULIA_CLANG_ARTIFACTS_DIR}/include>
    $<BUILD_INTERFACE:${JULIA_LLVM_ARTIFACTS_DIR}/include>
    $<BUILD_INTERFACE:${LLVM_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)

set(PUB_HEADERS_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_property(TARGET clangex APPEND PROPERTY
    PUBLIC_HEADER ${PUB_HEADERS_PREFIX}/libclangex.h
                  ${PUB_HEADERS_PREFIX}/CXCompilerInvocation.h
                  ${PUB_HEADERS_PREFIX}/CXCompilerInstance.h
                  ${PUB_HEADERS_PREFIX}/CXCodeGenOptions.h
                  ${PUB_HEADERS_PREFIX}/CXDiagnosticOptions.h
                  ${PUB_HEADERS_PREFIX}/CXDiagnostic.h
                  ${PUB_HEADERS_PREFIX}/CXError.h
                  ${PUB_HEADERS_PREFIX}/CXFileManager.h
                  ${PUB_HEADERS_PREFIX}/CXIntrusiveRefCntPtr.h
                  ${PUB_HEADERS_PREFIX}/CXTriple.h
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
