cmake_minimum_required(VERSION 3.25)

project(GDHSupportMod VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

setup_geode_mod(GDHSupportMod)

add_library(GDHSupportMod SHARED src/main.cpp)
target_link_libraries(GDHSupportMod PUBLIC Geode)
