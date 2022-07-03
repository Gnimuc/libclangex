cmake_minimum_required(VERSION 3.17)

project(LibClangEx LANGUAGES CXX)

# Turn on using VS solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Options
option(LLVM_ASSERT_BUILD "build with LLVM assert" OFF)

# TODO: Autodetect
set(LLVM_VERSION_MAJOR 13 CACHE STRING "LLVM Version to target")
message("LLVM version " ${LLVM_VERSION_MAJOR})

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_library(clangex SHARED)

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

find_library(ClangCPP NAMES clang-cpp HINTS "${CLANG_DIR}/lib")
message(STATUS "Found Clang: ${ClangCPP}")

find_library(LLVM NAMES LLVM HINTS "${LLVM_DIR}/lib")
message(STATUS "Found LLVM: ${LLVM}")

add_subdirectory(lib)
add_subdirectory(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")

set(CLANG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/upstream/${LLVM_VERSION_MAJOR})
target_sources(clangex PRIVATE ${CLANG_SRC}/libclang/CXString.cpp)

target_include_directories(clangex PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CLANG_DIR}/include>
    $<BUILD_INTERFACE:${LLVM_DIR}/include>
    $<BUILD_INTERFACE:${CLANG_SRC}>
    $<INSTALL_INTERFACE:include>)
    
target_compile_features(clangex PRIVATE cxx_std_14)

if(LLVM_ASSERT_BUILD)
    message(STATUS "Build with LLVM assert. This means Julia should also be built with `LLVM_ASSERTIONS=1`.")
    target_compile_definitions(clangex PUBLIC "LLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING=1")  # hack for the assert build
else()
    message(STATUS "Build without LLVM assert.")
endif()

if (WIN32)
    target_compile_definitions(clangex PUBLIC "_CINDEX_LIB_")
endif(WIN32)

target_link_libraries(clangex LINK_PUBLIC ${ClangCPP} ${LLVM})

include(cmake/install_config.cmake)
