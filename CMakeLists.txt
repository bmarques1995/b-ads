cmake_minimum_required(VERSION 3.28)

project(b-ads VERSION 0.1.0)

option(BUILD_SHARED_LIBS "Build project as shared libs" ON)
option(B_ADS_BUILD_SAMPLES "Build sample programs" OFF)
option(B_ADS_BUILD_TESTS "Build sample programs" OFF)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH})
include(resource_processor)

#find_package(Qt6 COMPONENTS Core Gui Widgets)
#find_program(QT_LRELEASE lrelease REQUIRED)
#find_program(QT_RCC rcc REQUIRED)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

#set(QT_AUTOGEN_SUFFIX "_autogen")

add_subdirectory(b_ads)
if(B_ADS_BUILD_SAMPLES)
    add_subdirectory(b_ads_samples)
endif()
if(B_ADS_BUILD_TESTS)
    add_subdirectory(b_ads_tests)
endif()
