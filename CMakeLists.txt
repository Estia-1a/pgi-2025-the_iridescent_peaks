cmake_minimum_required(VERSION 3.15)
project(freud VERSION 1.0.1 DESCRIPTION "freud is an image analyst" LANGUAGES C)

set(CMAKE_C_STANDARD 11)
add_compile_options(-Wall -Wextra)

file(GLOB SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/src/*.c"
)

add_executable(freud ${SOURCE_FILES})

target_include_directories(freud PUBLIC
    "${CMAKE_SOURCE_DIR}/estia-image/include"
    "${CMAKE_SOURCE_DIR}/getopt/include"
)

find_library(ESTIA_IMAGE_LIB
    NAMES estia-image libestia-image
    HINTS "${CMAKE_SOURCE_DIR}/estia-image/lib"
)
if(ESTIA_IMAGE_LIB AND NOT ESTIA_IMAGE_LIB STREQUAL "ESTIA_IMAGE_LIB-NOTFOUND")
    message(STATUS "Linking estia-image: ${ESTIA_IMAGE_LIB}")
    target_link_libraries(freud PUBLIC ${ESTIA_IMAGE_LIB})
else()
    message(WARNING "estia-image library not found, skipping link.")
endif()

find_library(GETOPT_LIB
    NAMES getopt
    HINTS "${CMAKE_SOURCE_DIR}/getopt/lib"
)
if(GETOPT_LIB AND NOT GETOPT_LIB STREQUAL "GETOPT_LIB-NOTFOUND")
    message(STATUS "Linking getopt: ${GETOPT_LIB}")
    target_link_libraries(freud PUBLIC ${GETOPT_LIB})
else()
    message(WARNING "getopt library not found, skipping link.")
endif()

install(TARGETS freud
    CONFIGURATIONS Debug
    RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}"
)
install(TARGETS freud
    CONFIGURATIONS Release
    RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/dist"
)
