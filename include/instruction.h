#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstdint>

enum class InstrType {
    R_TYPE,
    I_TYPE,
    S_TYPE,
    UNKNOWN
};

struct Instruction {
    uint32_t raw;

    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct7;
    int32_t imm;

    InstrType type;

    Instruction(uint32_t rawInstr);
};

#endif
