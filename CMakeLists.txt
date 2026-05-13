cmake_minimum_required(VERSION 3.28)

project(b-ads VERSION 0.1.0)

option(BUILD_SHARED_LIBS "Build project as shared libs" ON)
option(B_ADS_BUILD_SAMPLES "Build sample programs" OFF)
option(B_ADS_BUILD_TESTS "Build sample programs" OFF)
option(USE_DEV_DEPENDENCIES "Build with devtools" OFF)

if(USE_DEV_DEPENDENCIES)
    include(FetchContent)   
    FetchContent_Declare(
        helpers_source
        GIT_REPOSITORY https://github.com/bmarques1995/cmake_helpers.git
        GIT_TAG 350e044bfe35ffde1143f51df6e39531dd8f48aa
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers
    )
    FetchContent_MakeAvailable(helpers_source)
    set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_helpers;${CMAKE_MODULE_PATH})

    include(dep_tracer)

    trace_dependency(NAME Qt6 COMPONENTS Core Widgets Gui Test INSTALL_SCRIPT "${PROJECT_SOURCE_DIR}/cmake_helpers/installers_examples/qtbase.cmake.json")
    trace_dependency(NAME Qt6 COMPONENTS LinguistTools INSTALL_SCRIPT "${PROJECT_SOURCE_DIR}/cmake_helpers/installers_examples/qttools.cmake.json")
    if((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD"))
        trace_dependency(NAME Qt6 COMPONENTS WaylandClient INSTALL_SCRIPT "${PROJECT_SOURCE_DIR}/cmake_helpers/installers_examples/qtwayland.cmake.json")
        list(APPEND CMAKE_PROGRAM_PATH "${CMAKE_PREFIX_PATH}/libexec")
    endif()
endif()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH})
include(resource_processor)

find_package(Qt6 COMPONENTS Core Gui Widgets Test)
find_program(QT_LRELEASE lrelease REQUIRED)
find_program(QT_RCC rcc REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_AUTOGEN_SUFFIX "_autogen")

add_subdirectory(b_ads)
if(B_ADS_BUILD_SAMPLES)
    add_subdirectory(b_ads_samples)
endif()
if(B_ADS_BUILD_TESTS)
    add_subdirectory(b_ads_tests)
endif()
