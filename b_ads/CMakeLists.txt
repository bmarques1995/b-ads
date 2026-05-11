set(TARGET_NAME b_ads)

#process_resources(${CMAKE_CURRENT_SOURCE_DIR} "res/*.qrc")

file(GLOB_RECURSE B_ADS_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE B_ADS_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "include/b_ads/*.h")
file(GLOB_RECURSE B_ADS_RSCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "res/*.cpp")

add_library(${TARGET_NAME} ${B_ADS_SRCS} ${B_ADS_RSCS} ${B_ADS_HDRS})

if(BUILD_SHARED_LIBS)
    target_compile_definitions(${TARGET_NAME} PRIVATE B_ADS_EXPORT)
    target_compile_definitions(${TARGET_NAME} INTERFACE B_ADS_IMPORT)
    target_compile_definitions(${TARGET_NAME} PUBLIC B_ADS_NAMESPACE_ENABLED)
endif()

target_include_directories(${TARGET_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}${QT_AUTOGEN_SUFFIX}>
												 $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/b_ads>
                                                 $<INSTALL_INTERFACE:include/b_ads>)

#target_link_libraries(${TARGET_NAME} PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)