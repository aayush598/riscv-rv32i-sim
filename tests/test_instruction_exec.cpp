#include "doctest.h"
#include "cpu.h"
#include "memory.h"
#include "instruction.h"

TEST_CASE("Execute ADDI with positive values") {
    Memory mem(1024 * 64); // 64KB memory (you can adjust this size)

    CPU cpu(mem);

    // Set rs1 = 10
    cpu.setRegister(2, 10); // x2 = 10

    // ADDI x5, x2, 20  → x5 = x2 + 20 = 30
    uint32_t raw = 0x01410293;  // imm=20, rs1=2, rd=5, opcode=0x13 (ADDI)
    Instruction instr(raw);
    cpu.execute(instr);

    CHECK(cpu.getRegister(5) == 30);
}
