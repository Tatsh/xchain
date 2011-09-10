cmake_minimum_required(VERSION 2.8.5)
project("CMakeExample")

set(CMAKE_SYSTEM_NAME iOS)
set(IOS_PREFIX "arm-apple-darwin-") 
set(CMAKE_C_COMPILER ${IOS_PREFIX}llvm-gcc)
set(CMAKE_CXX_COMPILER ${IOS_PREFIX}llvm-g++)

# These are from defaults with Xcode (Debug except without -DDEBUG)
set(CMAKE_C_FLAGS "-fmessage-length=0 -pipe -std=gnu99 -fpascal-strings -Wreturn-type -Wunused-variable")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -gdwarf-2 -miphoneos-version-min=2.0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -isysroot /home/tatsh/usr/arm-apple-darwin -O2")
set(CMAKE_CXX_FLAGS "-fmessage-length=0 -pipe -fpascal-strings -Wreturn-type -Wunused-variable")

# Fix your paths here
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/home/tatsh/usr/arm-apple-darwin/usr/include/c++/4.2.1")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/home/tatsh/usr/arm-apple-darwin/usr/include/c++/4.2.1/arm-apple-darwin10/v6")

set(CMAKE_EXE_LINKER_FLAGS "-dead_strip -framework UIKit -framework Foundation")

# set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB MAIN_SRC Classes/*.m)

include_directories(
  "${CMAKE_SOURCE_DIR}/Classes"
)

# Required to force gcc instead of g++
set_source_files_properties(
  ${MAIN_SRC}
  PROPERTIES
    LANGUAGE C
)

# set_source_files_properties(
#   # Add C++ source variables
#   PROPERTIES
#     LANGUAGE CXX
# )

add_executable(
  ${PROJECT_NAME}
  ${MAIN_SRC}
)
