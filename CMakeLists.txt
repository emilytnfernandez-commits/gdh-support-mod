cmake_minimum_required(VERSION 3.25)

project(GDHSupportMod VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Verificar que la variable GEODE_SDK existe (la acción de GitHub la provee)
if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

# Añadir el SDK como subdirectorio de CMake
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Archivos fuente de tu mod (asegúrate de que main.cpp esté dentro de src/)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Configurar el mod de Geode
setup_geode_mod(${PROJECT_NAME})

# Crear la librería compartida
add_library(${PROJECT_NAME} SHARED ${SOURCES})
