cmake_minimum_required(VERSION 3.17)

project(LibClangEx LANGUAGES CXX)

# Turn on using VS solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

find_package(Clang REQUIRED CONFIG)
message(STATUS "Found Clang ${Clang_PACKAGE_VERSION}")
message(STATUS "Using ClangConfig.cmake in: ${Clang_DIR}")

add_library(clangex SHARED)
add_subdirectory(lib)
add_subdirectory(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")

set(CLANG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/upstream/${LLVM_VERSION_MAJOR})
target_sources(clangex PRIVATE ${CLANG_SRC}/libclang/CXString.cpp)

target_include_directories(clangex PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${LLVM_INCLUDE_DIRS}>
    $<BUILD_INTERFACE:${Clang_INCLUDE_DIRS}>
    $<BUILD_INTERFACE:${CLANG_SRC}>
    $<INSTALL_INTERFACE:include>)
    
target_compile_features(clangex PRIVATE cxx_std_14)

if (WIN32)
    target_compile_definitions(clangex PUBLIC "_CINDEX_LIB_")
endif(WIN32)

target_link_libraries(clangex LINK_PUBLIC LLVM clang-cpp)

include(cmake/install_config.cmake)
