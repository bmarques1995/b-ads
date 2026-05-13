cmake_minimum_required(VERSION 3.28)
set(TARGET_NAME b_ads_tests)

file(GLOB_RECURSE TESTS_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE TESTS_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.h")

add_executable(${TARGET_NAME} ${TESTS_SRCS} ${TESTS_HDRS})
target_link_libraries(${TARGET_NAME} PRIVATE b_ads Qt6::Test)
target_include_directories(${TARGET_NAME} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)

if(WIN32)
    target_link_options(${TARGET_NAME} PRIVATE "/ENTRY:mainCRTStartup")
    set_target_properties(${TARGET_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
elseif(APPLE)
    set_target_properties(${TARGET_NAME} PROPERTIES MACOSX_BUNDLE TRUE)
endif()

install(TARGETS ${TARGET_NAME}
        RUNTIME DESTINATION "bin"
        COMPONENT ${PACKAGE_COMPONENT})
