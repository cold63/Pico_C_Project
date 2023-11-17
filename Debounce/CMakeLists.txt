cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(debounce C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

        
# Initialize the SDK
pico_sdk_init()


add_executable(debounce
            main.c
        )


# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(debounce pico_stdlib)

# enable usb output, disable uart output
#pico_enable_stdio_usb(debounce 0)
#pico_enable_stdio_uart(debounce 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(debounce)
