cmake_minimum_required(VERSION 3.0.0)
project(hamada VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED 23)

if(MSVC)
  set(CMAKE_CXX_FLAGS "/DEBUG /W4 /EHsc")
else()
  set(CMAKE_CXX_FLAGS "-Wall -g -O0")
endif()

include(CTest)
enable_testing(true)
add_subdirectory(Lexer)
add_subdirectory(Utility)
add_subdirectory(Diagnostics)
add_subdirectory(Parser)

add_executable(hamada main.cpp)

target_link_libraries(${PROJECT_NAME} Lexer)
target_link_libraries(${PROJECT_NAME} Parser)