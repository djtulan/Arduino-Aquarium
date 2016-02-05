set(PROJECT_NAME aquarium)

set(CMAKE_ARDUINO_PATH ~/workspace/arduino/arduino-cmake) #path to arduino-cmake
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_ARDUINO_PATH}/cmake/ArduinoToolchain.cmake) # Arduino Toolchain
set(CMAKE_EXTERNAL_LIBS_PATH ~/sketchbook/libraries) # arduino external libs

# Link external libs directories (as Arduino-IDE uses it)
link_directories(${CMAKE_EXTERNAL_LIBS_PATH})
link_directories(/usr/share/arduino/libraries)

cmake_minimum_required(VERSION 2.8)

project(${PROJECT_NAME} C CXX)

# find_package(Arduino 1.0 REQUIRED)

# Define your Arduino board (below is for Arduino nano atmega328)
set(${PROJECT_NAME}_BOARD atmega328)

# Define the source code
set(${PROJECT_NAME}_SRCS ${PROJECT_NAME}.cpp display.cpp display_main.cpp display_setup.cpp icons.cpp)

# Define the port for uploading code to the Arduino
set(${PROJECT_NAME}_PORT /dev/ttyUSB0)

# Command to generate code arduino firmware (.hex file)
generate_arduino_firmware(${PROJECT_NAME})
