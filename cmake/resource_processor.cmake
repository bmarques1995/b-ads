function(process_resources TARGET_DIRECTORY FILE_PATTERN)
    file(GLOB_RECURSE TARGET_RSCS RELATIVE ${TARGET_DIRECTORY} ${FILE_PATTERN})
    foreach(RSC_FILE ${TARGET_RSCS})
        message(STATUS "Processing ${RSC_FILE}")
        execute_process(
            COMMAND ${QT_RCC} ${CMAKE_CURRENT_SOURCE_DIR}/${RSC_FILE} -g cpp -o ${CMAKE_CURRENT_SOURCE_DIR}/${RSC_FILE}.cpp
            COMMAND_ERROR_IS_FATAL ANY
        )
    endforeach()
endfunction()

macro(redirect_ui_dir TARGET_NAME DIRECTORY)
    set_target_properties(${TARGET_NAME} PROPERTIES
        AUTOUIC_SEARCH_PATHS
            "${DIRECTORY}"
    )
endmacro()