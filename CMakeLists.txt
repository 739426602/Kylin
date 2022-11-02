cmake_minimum_required(VERSION 3.5)

project(Kylin)

add_definitions(-DUNICODE -D_UNICODE)

include_directories("${PROJECT_SOURCE_DIR}/Framework/Common")
include_directories("${PROJECT_SOURCE_DIR}/Framework/Interface")

add_subdirectory(Framework)
add_subdirectory(Platform)
