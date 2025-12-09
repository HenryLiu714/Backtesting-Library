cmake_minimum_required(VERSION 3.15)
project(Backtester LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Collect all source files ---
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "include/*.h" "include/*.hpp")

# Now find pybind11
find_package(pybind11 CONFIG REQUIRED)

# --- Core library ---
add_library(core STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_include_directories(core PUBLIC include)

# --- Python bindings ---
pybind11_add_module(Backtester bindings/bindings.cpp)
target_link_libraries(Backtester PRIVATE core)

# --- Install the compiled module to python/backtester ---
install(
    TARGETS Backtester
    DESTINATION python/backtester
)