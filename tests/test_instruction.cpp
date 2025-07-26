#include "doctest.h"
#include "instruction.h"

TEST_CASE("Instruction Decode: ADDI") {
    uint32_t raw = 0x00500293; // addi x5, x0, 5
    Instruction instr(raw);

    CHECK(instr.opcode == 0x13);
    CHECK(instr.rd == 5);
    CHECK(instr.rs1 == 0);
    CHECK(instr.imm == 5);
}
