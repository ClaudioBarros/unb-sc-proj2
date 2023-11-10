# AES-128 Simple Implementation

This repository contains a simple implementation of the AES-128 (Advanced Encryption Standard) algorithm, providing a basic yet functional example of how AES-128 encryption and decryption can be performed. AES-128 is a widely used symmetric encryption algorithm that operates on fixed-size blocks of data (128 bits or 16 bytes) and supports key sizes of 128, 192, or 256 bits. This project focuses on the 128-bit key variant.

## Features

- **AES-128 Encryption:** Encrypt plaintext data using AES-128 algorithm.
- **AES-128 Decryption:** Decrypt ciphertext data back to the original plaintext.
- **CTR and ECB Modes of Operation** 

- **Customizable:** Allows a custom number of main Rounds.

- **Simple and Understandable:** The implementation is kept simple and easy to understand, making it suitable for educational purposes and learning about the AES-128 algorithm.

## Prerequisites

* **C++ Compiler** - needs to support at least the **C++11** standard, i.e. *MSVC*, *GCC*, *Clang*

## Building 

To build the project using **CMake**, all you need to do, assuming you have **CMake** installed and you're running in a linux machine, is run a similar routine to the the one below:

For a Debug build:
```bash
mkdir build/ && cd build/
cmake -S --build . 
cmake -B./ -S../-DCMAKE_BUILD_TYPE=Debug
make
```
For a Release build:
```bash
mkdir build/ && cd build/
cmake -S --build . 
cmake -B./ -S../-DCMAKE_BUILD_TYPE=Release
make
```
## Running the tests

The tests files are located in the testfiles folder and need to be placed in the same folder as the executable.

## Authors

* **Cláudio Barros** - 190097591 - [@claudiobarros](https://github.com/claudiobarros) 

