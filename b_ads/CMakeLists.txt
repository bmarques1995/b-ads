set(TARGET_NAME b_ads)

process_resources(${CMAKE_CURRENT_SOURCE_DIR} "res/*.qrc")

file(GLOB_RECURSE B_ADS_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE B_ADS_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "include/b_ads/*.h")
file(GLOB_RECURSE B_ADS_RSCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "res/*.cpp")

add_library(${TARGET_NAME} ${B_ADS_SRCS} ${B_ADS_RSCS} ${B_ADS_HDRS})

if(BUILD_SHARED_LIBS)
    target_compile_definitions(${TARGET_NAME} PRIVATE B_ADS_EXPORT INTERFACE B_ADS_IMPORT)
endif()

target_compile_definitions(${TARGET_NAME} PUBLIC B_ADS_NAMESPACE_ENABLED)

target_include_directories(${TARGET_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}${QT_AUTOGEN_SUFFIX}>
												 $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/b_ads>
                                                 $<INSTALL_INTERFACE:include/b_ads>)

target_link_libraries(${TARGET_NAME} PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)

set(CONFIG_BASE_DIR "lib/cmake/")

set(B_ADS_GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(B_ADS_VERSION_CONFIG "${B_ADS_GENERATED_DIR}/b_adsConfigVersion.cmake")
set(B_ADS_PROJECT_CONFIG "${B_ADS_GENERATED_DIR}/b_adsConfig.cmake")
set(B_ADS_TARGETS_EXPORT_NAME "b_adsTargets")
set(B_ADS_CONFIG_INSTALL_DIR "${CONFIG_BASE_DIR}b_ads")
set(B_ADS_NAMESPACE "b_ads::")
set(B_ADS_VERSION ${PROJECT_VERSION})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${B_ADS_VERSION_CONFIG}" VERSION ${B_ADS_VERSION} COMPATIBILITY SameMajorVersion
)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in" "${B_ADS_PROJECT_CONFIG}" @ONLY)

# Install cmake config files
install(
    FILES "${B_ADS_PROJECT_CONFIG}" "${B_ADS_VERSION_CONFIG}"
    DESTINATION "${B_ADS_CONFIG_INSTALL_DIR}")

install(
    EXPORT "${B_ADS_TARGETS_EXPORT_NAME}"
    NAMESPACE "${B_ADS_NAMESPACE}"
    DESTINATION "${B_ADS_CONFIG_INSTALL_DIR}")

set(PACKAGE_COMPONENT "b_ads")
install(TARGETS ${PACKAGE_TARGET_NAME}
        EXPORT ${B_ADS_TARGETS_EXPORT_NAME}
        RUNTIME DESTINATION "bin"
        COMPONENT ${PACKAGE_COMPONENT}
        ARCHIVE DESTINATION "lib"
        COMPONENT ${PACKAGE_COMPONENT}
        LIBRARY DESTINATION "lib"
        COMPONENT ${PACKAGE_COMPONENT})

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/b_ads/
        DESTINATION include/b_ads
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp" PATTERN "*.hh" PATTERN "*.hxx" PATTERN "*.h++" 
        PATTERN "*.i" PATTERN "*.ipp" PATTERN "*.ii" PATTERN "*.ixx" PATTERN "*.i++" PATTERN "*.inl" PATTERN "*.inc")