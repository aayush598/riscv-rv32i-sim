#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <array>

class CPU {
public:
    CPU();

    void reset();                // Reset all registers and PC
    void printRegisters() const; // Debugging: print all register values

    // Getters for registers and PC
    uint32_t getRegister(int index) const;
    void setRegister(int index, uint32_t value);
    uint32_t getPC() const;
    void setPC(uint32_t value);

private:
    std::array<uint32_t, 32> regs; // 32 general-purpose registers
    uint32_t pc;                   // Program counter
};

#endif
