set(TARGET_NAME b_ads_sample)

file(GLOB_RECURSE SAMPLE_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE SAMPLE_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.h")
file(GLOB_RECURSE SAMPLE_UIS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/ui/*.ui")

add_executable(${TARGET_NAME} ${SAMPLE_SRCS} ${SAMPLE_HDRS})
target_link_libraries(${TARGET_NAME} PRIVATE b_ads)
target_include_directories(${TARGET_NAME} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}${QT_AUTOGEN_SUFFIX}>
                                                  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/dialogs>
                                                  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
redirect_ui_dir(${TARGET_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/ui)

if(WIN32)
    target_link_options(${TARGET_NAME} PRIVATE "/ENTRY:mainCRTStartup")
    set_target_properties(${TARGET_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
elseif(APPLE)
    set_target_properties(${TARGET_NAME} PROPERTIES MACOSX_BUNDLE TRUE)
endif()

install(TARGETS ${TARGET_NAME}
        RUNTIME DESTINATION "bin"
        COMPONENT ${PACKAGE_COMPONENT})
