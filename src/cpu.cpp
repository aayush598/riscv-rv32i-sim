#include "cpu.h"
#include "memory.h"
#include <iostream>
#include <iomanip>

CPU::CPU(Memory& mem) : memory(mem) {
    reset();
}

void CPU::reset() {
    regs.fill(0); // Set all 32 registers to 0
    pc = 0;        // Start execution at address 0x00000000
}

uint32_t CPU::getRegister(int index) const {
    if (index < 0 || index > 31) return 0;
    return regs[index];
}

void CPU::setRegister(int index, uint32_t value) {
    if (index <= 0 || index > 31) return; // x0 is always 0
    regs[index] = value;
}

uint32_t CPU::getPC() const {
    return pc;
}

void CPU::setPC(uint32_t value) {
    pc = value;
}

void CPU::printRegisters() const {
    std::cout << "\n==== REGISTER FILE ====\n";
    for (int i = 0; i < 32; i++) {
        std::cout << "x" << std::setw(2) << std::left << i << ": 0x"
                  << std::hex << std::setw(8) << std::setfill('0') << regs[i];
        if ((i + 1) % 4 == 0) std::cout << "\n";
        else std::cout << "  ";
    }
    std::cout << "PC : 0x" << std::hex << pc << "\n";
}

uint32_t CPU::fetch() {
    uint32_t instr = memory.read32(pc); // Fetch 32-bit instruction
    pc += 4;                             // Advance PC (default for RISC-V)
    return instr;
}