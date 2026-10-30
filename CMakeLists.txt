cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GDHSupportMod VERSION 1.0.0)

# 1. Buscar todos los archivos .cpp dentro de la carpeta src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# 2. Crear la librería compartida PRIMERO
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# 3. Importar el SDK de Geode desde la variable de entorno que crea GitHub Actions
if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# 4. Configurar el mod (DEBE IR AL FINAL DE TODO)
setup_geode_mod(${PROJECT_NAME})
