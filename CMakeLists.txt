#==============================================================================
# CMakeLists file for math
#==============================================================================
cmake_minimum_required(VERSION 3.0)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET ${CBTEK_MATH_LIBRARY})
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS"${CURR_TARGET}_HEADERS")
include_directories(inc)

#==============================================================================
# Include Source Files
#==============================================================================
file(GLOB CURR_TARGET_SOURCES "src/*.cpp")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*")

#==============================================================================
# Add Library
#==============================================================================
add_library(${CURR_TARGET}
            ${LIBRARY_MODE}
            ${CURR_TARGET_SOURCES}
            ${CURR_TARGET_HEADERS})

add_dependencies(${CURR_TARGET} ${CBTEK_UTILITY_LIBRARY})
