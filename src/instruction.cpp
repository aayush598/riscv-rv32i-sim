#include "instruction.h"

Instruction::Instruction(uint32_t rawInstr) : raw(rawInstr) {
    opcode = rawInstr & 0x7F;

    switch (opcode) {
        case 0x33: // R-type
            type = InstrType::R_TYPE;
            rd     = (rawInstr >> 7)  & 0x1F;
            funct3 = (rawInstr >> 12) & 0x07;
            rs1    = (rawInstr >> 15) & 0x1F;
            rs2    = (rawInstr >> 20) & 0x1F;
            funct7 = (rawInstr >> 25) & 0x7F;
            imm    = 0;
            break;

        case 0x13: // I-type
            type = InstrType::I_TYPE;
            rd     = (rawInstr >> 7)  & 0x1F;
            funct3 = (rawInstr >> 12) & 0x07;
            rs1    = (rawInstr >> 15) & 0x1F;
            rs2    = 0;
            funct7 = 0;
            imm    = static_cast<int32_t>(rawInstr) >> 20; // Sign-extend
            break;

        case 0x23: // S-type
            type = InstrType::S_TYPE;
            funct3 = (rawInstr >> 12) & 0x07;
            rs1    = (rawInstr >> 15) & 0x1F;
            rs2    = (rawInstr >> 20) & 0x1F;
            funct7 = 0;
            rd     = 0;
            imm = ((rawInstr >> 7) & 0x1F) | (((rawInstr >> 25) & 0x7F) << 5);
            // Sign-extend if needed
            if (imm & 0x800) imm |= 0xFFFFF000;
            break;

        default:
            type = InstrType::UNKNOWN;
            rd = rs1 = rs2 = funct3 = funct7 = 0;
            imm = 0;
            break;
    }
}
