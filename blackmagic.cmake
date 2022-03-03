
SET(S ${CMAKE_SOURCE_DIR}/blackmagic/src)
SET(B ${CMAKE_SOURCE_DIR}/bridge )
SET(T ${CMAKE_SOURCE_DIR}/blackmagic/src/target )
SET(BRIDGE ${CMAKE_SOURCE_DIR}/bridge/src)

SET(BRIDGE_SRCS ${BRIDGE}/bridge.cpp)
SET(BM_SRC ${S}/command.c ${S}/crc32.c ${S}/exception.c ${S}/gdb_hostio.c ${S}/gdb_main.c ${S}/gdb_packet.c ${S}/hex_utils.c ${S}/morse.c ${S}/remote.c ${S}/timing.c)
SET(BM_TARGET ${T}/adiv5.c ${T}/adiv5_swdp.c ${T}/cortexm.c ${T}/jtag_devs.c
    ${T}/jtagtap_generic.c ${T}/lmi.c ${T}/lpc15xx.c ${T}/lpc43xx.c
    ${T}/lpc_common.c ${T}/nrf51.c ${T}/rp.c ${T}/sam4l.c ${T}/samx5x.c
    ${T}/stm32f4.c ${T}/stm32h7.c ${T}/stm32l4.c ${T}/target.c
    ${T}/adiv5_jtagdp.c ${T}/cortexa.c ${T}/efm32.c ${T}/jtag_scan.c ${T}/kinetis.c ${T}/lpc11xx.c ${T}/lpc17xx.c ${T}/lpc546xx.c ${T}/msp432.c ${T}/nxpke04.c ${T}/sam3x.c ${T}/samd.c ${T}/stm32f1.c ${T}/stm32g0.c ${T}/stm32l0.c ${T}/swdptap_generic.c)
add_library(blackmagic STATIC ${BM_SRC} ${BRIDGE_SRCS})
target_include_directories( blackmagic PRIVATE ${S}/include ${B}/include ${T} ${CMAKE_BINARY_DIR}/config ${CMAKE_SOURCE_DIR}/libopencm3/include)
target_compile_definitions(blackmagic PRIVATE PLATFORM_IDENT="ESP32")
