#include <iostream>
#include "cpu.h"
#include "memory.h"
#include "loader.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./riscv_sim <binary_file>\n";
        return 1;
    }

    const std::string binFile = argv[1];
    const uint32_t baseAddress = 0x00010000;

    Memory mem(1024 * 1024); // 1 MB
    CPU cpu;

    try {
        std::vector<uint8_t> program = Loader::loadBinaryFile(binFile);
        mem.loadProgram(program, baseAddress);
        cpu.setPC(baseAddress);

        std::cout << "[+] Loaded binary: " << binFile << "\n";
        std::cout << "[+] PC initialized to: 0x" << std::hex << cpu.getPC() << "\n";
        std::cout << "[+] Program size: " << std::dec << program.size() << " bytes\n";

    } catch (const std::exception& e) {
        std::cerr << "[!] Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
