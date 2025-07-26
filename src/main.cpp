#include "cpu.h"
#include "memory.h"
#include <vector>
#include <iostream>

int main() {
    Memory mem(1024); // 1 KB memory
    CPU cpu(mem);

    // Manually write a small program (or fake binary) to memory
    std::vector<uint8_t> testProgram = {
        0x93, 0x00, 0x10, 0x00,   // addi x1, x0, 1
        0x13, 0x01, 0x11, 0x00,   // addi x2, x2, 1
    };

    mem.loadProgram(testProgram, 0); // Load program at address 0x00

    // Simulate a few fetches (no decode/exec yet)
    uint32_t instr1 = cpu.fetch();
    uint32_t instr2 = cpu.fetch();

    std::cout << "\nFetched Instructions:\n";
    std::cout << "Instr1: 0x" << std::hex << instr1 << "\n";
    std::cout << "Instr2: 0x" << std::hex << instr2 << "\n";

    // Update some registers manually to simulate execution effect
    cpu.setRegister(1, 0x12345678);
    cpu.setRegister(2, 0xAABBCCDD);

    cpu.printRegisters();
    mem.dumpMemory(0, 16); // Dump first 16 bytes

    return 0;
}
