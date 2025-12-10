cmake_minimum_required(VERSION 3.15)
project(Backtester LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. Find Python Headers and Libraries ---
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# --- 2. Find pybind11 ---
find_package(pybind11 CONFIG REQUIRED)

# --- 3. Collect sources ---
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "include/*.h" "include/*.hpp")

# --- 4. Core C++ library ---
add_library(core STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS})

# Make include/backtester.h visible
target_include_directories(core PUBLIC include)

# Give the core engine access to Python headers
target_include_directories(core PUBLIC ${Python3_INCLUDE_DIRS})

# Link Python libs (libpython3.x.so) to core
target_link_libraries(core PUBLIC Python3::Python)
set_property(TARGET core PROPERTY POSITION_INDEPENDENT_CODE ON)

# --- 5. Python extension module ---
pybind11_add_module(Backtester bindings/bindings.cpp)

# Link in your core engine
target_link_libraries(Backtester PRIVATE core)

# --- 6. Installation target ---
install(
    TARGETS Backtester
    DESTINATION python/backtester
)
