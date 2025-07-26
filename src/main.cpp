#include <iostream>
#include "cpu.h"
#include "memory.h"

int main() {
    Memory mem(1024 * 1024); // 1 MB

    // Test: write and read back 32-bit value
    mem.write32(100, 0xDEADBEEF);
    uint32_t val = mem.read32(100);

    std::cout << "Written: 0xDEADBEEF, Read: 0x" << std::hex << val << "\n";

    // Bounds check
    try {
        mem.write8(1024 * 1024 + 1, 0xFF);
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }

    return 0;
}
