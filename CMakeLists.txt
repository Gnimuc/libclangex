cmake_minimum_required(VERSION 3.15.0)

project(clangex)

set(target clangex)

add_library(${target} SHARED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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

target_sources(${target} PRIVATE src/libclangex.cpp)
target_sources(${target} PRIVATE src/CXCodeGenOptions.cpp)
target_sources(${target} PRIVATE src/CXCompilerInstance.cpp)
target_sources(${target} PRIVATE src/CXCompilerInvocation.cpp)
target_sources(${target} PRIVATE src/CXDiagnostic.cpp)
target_sources(${target} PRIVATE src/CXDiagnosticOptions.cpp)
target_sources(${target} PRIVATE src/CXFileManager.cpp)
target_sources(${target} PRIVATE src/CXMemoryBuffer.cpp)
target_sources(${target} PRIVATE src/CXSourceManager.cpp)
target_sources(${target} PRIVATE src/CXASTUnit.cpp)

# set(CMAKE_SKIP_RPATH ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")

target_include_directories(${target} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CLANG_DIR}/include>
    $<BUILD_INTERFACE:${LLVM_DIR}/include>
    # $<BUILD_INTERFACE:${LLVM_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)
    
target_compile_features(${target} PRIVATE cxx_std_14)

set(pub_hdrs ${CMAKE_CURRENT_SOURCE_DIR}/include/libclangex.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/CXCodeGenOptions.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/CXCompilerInstance.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/CXCompilerInvocation.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/CXDiagnostic.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/CXDiagnosticOptions.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/CXIntrusiveRefCntPtr.h
            )
set_target_properties(${target} PROPERTIES PUBLIC_HEADER "${pub_hdrs}")

target_link_libraries(${target} LINK_PUBLIC ${ClangCPP} ${LLVM})

install(TARGETS ${target}
        EXPORT ${target}Targets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        INCLUDES DESTINATION include
        PUBLIC_HEADER DESTINATION include)

install(EXPORT ${target}Targets
        NAMESPACE ${target}::
        FILE ${target}-config.cmake
        DESTINATION lib/cmake/${target})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json DESTINATION share)
