cmake_minimum_required(VERSION 3.5)

project(espMagic C CXX)
include(./platformConfig.cmake)

# Include for ESP-IDF build system functions
include($ENV{IDF_PATH}/tools/cmake/idf.cmake)
# Create idf::{target} and idf::freertos static libraries
idf_build_process("${TARGET}"
                    # try and trim the build; additional components
                    # will be included as needed based on dependency tree
                    #
                    # although esptool_py does not generate static library,
                    # processing the component is needed for flashing related
                    # targets and file generation
                    COMPONENTS "${TARGET}" freertos esptool_py esp_common driver
                    SDKCONFIG ${CMAKE_CURRENT_LIST_DIR}/sdkconfig
                    BUILD_DIR ${CMAKE_BINARY_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(elf_file ${CMAKE_PROJECT_NAME}.elf)
add_executable(${elf_file} src/main.cpp)


target_link_libraries(${elf_file} "idf::${TARGET}" idf::freertos idf::spi_flash idf::nvs_flash blackmagic)
# Attach additional targets to the executable file for flashing,
# linker script generation, partition_table generation, etc.
idf_build_executable(${elf_file})

include(./blackmagic.cmake)
