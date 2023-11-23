cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    comp-4300-init
    VERSION 0.1.0
    DESCRIPTION "COMP 4300 init"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    comp-4300-init_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    comp-4300-init_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(comp-4300-init_lib PUBLIC cxx_std_20)

find_package(fmt REQUIRED)
target_link_libraries(comp-4300-init_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(comp-4300-init_exe source/main.cpp)
add_executable(comp-4300-init::exe ALIAS comp-4300-init_exe)

set_property(TARGET comp-4300-init_exe PROPERTY OUTPUT_NAME comp-4300-init)

target_compile_features(comp-4300-init_exe PRIVATE cxx_std_20)

target_link_libraries(comp-4300-init_exe PRIVATE comp-4300-init_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT comp-4300-init_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of comp-4300-init"
  )
endif()

include(cmake/dev-mode.cmake)
