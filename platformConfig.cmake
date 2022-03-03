#!/usr/bin/env bash
SET(TARGET "esp32c3" CACHE INTERNAL "")
SET(IDF_PATH "/opt/esp/esp-idf" CACHE INTERNAL "")
SET(IDF_TC "/home/fx/.espressif/tools/riscv32-esp-elf/esp-2021r2-patch3-8.4.0/riscv32-esp-elf/bin" CACHE INTERNAL "")
#
SET(ENV{TARGET} "${TARGET}")
#
SET(CMAKE_TOOLCHAIN_FILE ${IDF_PATH}/tools/cmake/toolchain-${TARGET}.cmake)

set(CMAKE_C_COMPILER ${IDF_TC}/riscv32-esp-elf-gcc CACHE INTERNAL "")
set(CMAKE_CXX_COMPILER ${IDF_TC}/riscv32-esp-elf-g++ CACHE INTERNAL "")
set(CMAKE_ASM_COMPILER ${IDF_TC}/riscv32-esp-elf-gcc CACHE INTERNAL "")

SET(CMAKE_C_COMPILER_FORCED TRUE CACHE INTERNAL "")
SET(CMAKE_CXX_COMPILER_FORCED TRUE CACHE INTERNAL "")

