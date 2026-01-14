# HID Tool

Minimal C++ command-line tool for working with USB HID devices using HIDAPI.

## Features
- Open device by VID/PID
- Send data to HID device
- Simple CMake build
- Windows (MSYS2 MinGW64)

## Build
```bash
mkdir build
cd build
cmake ..
cmake --build .

## Usage
hidtool <VID> <PID> -w <data>
