#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <array>
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

private:
    std::array<uint32_t, 32> regs;
    uint32_t pc;

    Memory& memory; // 👈 Reference to memory object
};

#endif
