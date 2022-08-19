

add_library(pico_sonic sonic.cpp)

target_link_libraries(pico_sonic hardware_gpio pico_stdlib)

