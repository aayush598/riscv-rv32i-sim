#include "doctest.h"
#include "cpu.h"
#include "memory.h"

TEST_CASE("Execute ADDI Instruction") {
    Memory mem(65536);

    CPU cpu(mem);

    // ADDI x6, x0, 42
    uint32_t raw = 0x02A00313; // imm=42, rs1=x0, rd=x6
    Instruction instr(raw);
    cpu.execute(instr);

    CHECK(cpu.getRegister(6) == 42);
}
