# HID Tool

Minimal C++ command-line tool for working with USB HID devices using HIDAPI.

Minimal C++ HIDAPI tool for Windows (MSYS2)

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
