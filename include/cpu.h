#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <array>
#include "instruction.h"

class Memory; // Forward declaration

class CPU {
public:
    CPU(Memory& mem);

    void reset();
    void printRegisters() const;

    uint32_t getRegister(int index) const;
    void setRegister(int index, uint32_t value);
    uint32_t getPC() const;
    void setPC(uint32_t value);

    uint32_t fetch();  // 👈 Fetch instruction from memory

    void run(uint32_t numInstructions);  // Run for N instructions (no decode/exec)
    
    Instruction decode(uint32_t rawInstr);

    void execute(const Instruction& instr);


private:
    std::array<uint32_t, 32> regs;
    uint32_t pc;

    Memory& memory; // 👈 Reference to memory object
};

#endif
