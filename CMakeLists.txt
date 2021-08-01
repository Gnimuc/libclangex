cmake_minimum_required(VERSION 3.17.0)

project(clangex)

set(target clangex)

option(LLVM_ASSERT_BUILD "build with LLVM assert" OFF)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_library(${target} SHARED)

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

target_sources(${target} PRIVATE lib/libclangex.cpp)
target_sources(${target} PRIVATE lib/CXASTConsumer.cpp)
target_sources(${target} PRIVATE lib/CXASTContext.cpp)
target_sources(${target} PRIVATE lib/CXCodeGen.cpp)
target_sources(${target} PRIVATE lib/CXCompilerInstance.cpp)
target_sources(${target} PRIVATE lib/CXCompilerInvocation.cpp)
target_sources(${target} PRIVATE lib/CXDiagnostic.cpp)
target_sources(${target} PRIVATE lib/CXDriver.cpp)
target_sources(${target} PRIVATE lib/CXFileManager.cpp)
target_sources(${target} PRIVATE lib/CXOptions.cpp)
target_sources(${target} PRIVATE lib/CXParser.cpp)
target_sources(${target} PRIVATE lib/CXPreprocessor.cpp)
target_sources(${target} PRIVATE lib/CXQualType.cpp)
target_sources(${target} PRIVATE lib/CXSema.cpp)
target_sources(${target} PRIVATE lib/CXSourceManager.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")

target_include_directories(${target} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CLANG_DIR}/include>
    $<BUILD_INTERFACE:${LLVM_DIR}/include>
    $<INSTALL_INTERFACE:include>)
    
target_compile_features(${target} PRIVATE cxx_std_14)

if(LLVM_ASSERT_BUILD)
    message(STATUS "Build with LLVM assert. This means Julia should also be built with `LLVM_ASSERTIONS=1`.")
    target_compile_definitions(${target} PUBLIC "LLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING=1")  # hack for the assert build
else()
    message(STATUS "Build without LLVM assert.")
endif()

if (WIN32)
    target_compile_definitions(${target} PUBLIC "_CINDEX_LIB_")
endif(WIN32)

set(pub_hdrs ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/libclangex.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXASTConsumer.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXASTContext.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXCodeGen.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXCompilerInstance.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXCompilerInvocation.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXDiagnostic.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXDriver.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXError.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXFileManager.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXOptions.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXParser.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXPreprocessor.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXQualType.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXSema.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXSourceManager.h
             ${CMAKE_CURRENT_SOURCE_DIR}/include/clang-ex/CXTypes.h
            )
set_target_properties(${target} PROPERTIES PUBLIC_HEADER "${pub_hdrs}")
set_target_properties(${target} PROPERTIES EXPORT_COMPILE_COMMANDS true) 

target_link_libraries(${target} LINK_PUBLIC ${ClangCPP} ${LLVM})

install(TARGETS ${target}
        EXPORT ${target}Targets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        INCLUDES DESTINATION include/clang-ex
        PUBLIC_HEADER DESTINATION include/clang-ex)

install(EXPORT ${target}Targets
        NAMESPACE ${target}::
        FILE ${target}-config.cmake
        DESTINATION lib/cmake/${target})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json DESTINATION share)
