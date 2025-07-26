#include "cpu.h"
#include "memory.h"
#include "instruction.h"
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
        std::cout << "x" << std::dec << std::setw(2) << std::left << i << ": 0x"
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

void CPU::run(uint32_t numInstructions) {
    std::cout << "\n==== BEGIN FETCH-DECODE-EXECUTE LOOP ====\n";

    for (uint32_t i = 0; i < numInstructions; ++i) {
        try {
            uint32_t rawInstr = fetch();
            std::cout << "PC: 0x" << std::hex << pc - 4
                      << " | Raw: 0x" << std::hex << rawInstr << "\n";

            Instruction instr = decode(rawInstr);
            execute(instr);

        } catch (const std::exception& e) {
            std::cerr << "CPU halted: " << e.what() << "\n";
            break;
        }
    }

    std::cout << "==== END LOOP ====\n";
}


Instruction CPU::decode(uint32_t rawInstr) {
    Instruction decoded(rawInstr); // just uses constructor logic
    return decoded;
}


void CPU::execute(const Instruction& instr) {
    switch (instr.opcode) {
        case 0x13: { // I-type (e.g., ADDI, ANDI, ORI)
            switch (instr.funct3) {
                case 0x0: { // ADDI
                    int32_t rs1_val = static_cast<int32_t>(regs[instr.rs1]);
int32_t imm_val = static_cast<int32_t>(instr.imm);
int32_t result = rs1_val + imm_val;
setRegister(instr.rd, static_cast<uint32_t>(result));

                    std::cout << "Executed ADDI: x" << instr.rd
                        << " = x" << instr.rs1 << " + " << instr.imm
                        << " -> " << result << "\n";

                    break;
                }
                default:
                    std::cerr << "Unsupported I-type funct3: " << std::hex << (int)instr.funct3 << "\n";
            }
            break;
        }

        default:
            std::cerr << "Unsupported opcode: 0x" << std::hex << (int)instr.opcode << "\n";
    }
}