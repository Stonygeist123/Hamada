add_library(
  Lexer
  Lexer/Lexer.cpp
  Lexer/Lexer.h
)

target_include_directories(Lexer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(Lexer Diagnostics)