#include "doctest.h"
#include "cpu.h"
#include "memory.h"

TEST_CASE("Instruction Fetch and PC Update") {
    Memory mem(65536);

    CPU cpu(mem);

    mem.write32(0x00000000, 0x00500293); // addi x5, x0, 5
    uint32_t fetched = cpu.fetch();
    CHECK(fetched == 0x00500293);
    CHECK(cpu.getPC() == 0x4); // PC should advance by 4
}
