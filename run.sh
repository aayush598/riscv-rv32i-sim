#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

echo "🔧 Building the RISC-V Simulator..."

# Create build directory if it doesn't exist
mkdir -p build
cd build

# Run CMake and Make
cmake ..
make

echo "🚀 Build completed."

# Run the simulator with optional argument
./riscv_rv32i_sim
