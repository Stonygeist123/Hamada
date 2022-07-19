add_library(
  Parser
  Parser/Parser.cpp
  Parser/Parser.h
  Parser/Expr.h
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(Parser PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(Parser Lexer)