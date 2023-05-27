#minimum version required
cmake_minimum_required(VERSION 3.20)

#name of the project
project(Clike)

#pre-build for lexer and yacc
execute_process(WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/src
                COMMAND flex tokenize.l
                COMMAND bison --header=[./include/parser.h] parser.y
)

#set flags
set(CMAKE_BUILD_TYPE "Debug")
set (CMAKE_CXX_STANDARD 14)

#add llvm
find_package(LLVM REQUIRED CONFIG)

if(LLVM_FOUND)
    message(STATUS "LLVM :${LLVM_PACKAGE_VERSION}")
    message(STATUS "llvm directory: ${LLVM_DIR}")
    # separate_arguments(LLVM_DEFINITIONS_LIST UNIX_COMMAND $)
    include_directories(${LLVM_INCLUDE_DIRS})
    add_definitions(${LLVM_DEFINITIONS})
else(LLVM_FOUND)
    message(STATUS "can'f found llvm")
endif(LLVM_FOUND)

include_directories(${CMAKE_CURRENT_LIST_DIR}/src/include)

#make the executable
file(GLOB SOURCE ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp ${CMAKE_CURRENT_LIST_DIR}/src/include/*.h)
add_executable(clike ${SOURCE})

#link
    execute_process(COMMAND llvm-config-14 --libs all
                    OUTPUT_VARIABLE llvm_libs)
    string(STRIP ${llvm_libs} llvm_libs)
    string(REPLACE " " ";" llvm_libs ${llvm_libs})
    target_link_libraries(clike ${llvm_libs})    