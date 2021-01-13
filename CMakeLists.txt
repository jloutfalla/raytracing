cmake_minimum_required(VERSION 3.13)

if (MSVC)
  add_compile_options(/W3 /WX)
else()
  add_compile_options(-W -Wall -Wextra -pedantic)
endif()

project(raytracing
  VERSION 0.1.0
  LANGUAGES CXX
)

set(SRC_FILES
  "src/main.cpp"
  "src/vec3.cpp"
  "src/color.cpp"
)

add_executable("${PROJECT_NAME}" "${SRC_FILES}")
target_compile_features("${PROJECT_NAME}" PRIVATE cxx_std_11)
set_target_properties("${PROJECT_NAME}" PROPERTIES CXX_EXTENSION OFF)

target_include_directories("${PROJECT_NAME}"
  PUBLIC
  "${PROJECT_SOURCE_DIR}/include")
