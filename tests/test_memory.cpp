#include "doctest.h"
#include "memory.h"

TEST_CASE("Memory Read/Write") {
    Memory mem(65536);


    mem.write32(0x00000000, 0xAABBCCDD);
    CHECK(mem.read32(0x00000000) == 0xAABBCCDD);

    mem.write8(0x00000010, 0x7F);
    CHECK(mem.read8(0x00000010) == 0x7F);
}
