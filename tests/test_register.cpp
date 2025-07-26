#include "doctest.h"
#include "cpu.h"
#include "memory.h"

TEST_CASE("Register File: Read/Write") {
    Memory mem(1024 * 64); // ✅ Allocate 64KB of memory
    CPU cpu(mem);

    cpu.setRegister(5, 123);
    CHECK(cpu.getRegister(5) == 123);

    cpu.setRegister(0, 999); // x0 must stay zero
    CHECK(cpu.getRegister(0) == 0);
}
