add_library(
  Diagnostics
  Diagnostics/Diagnostics.h
  Diagnostics/Diagnostics.cpp
)

target_include_directories(Diagnostics PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(Diagnostics Utility)