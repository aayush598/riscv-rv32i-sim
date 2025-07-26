#include "cpu.h"
#include "memory.h"
#include <vector>

int main() {
    Memory mem(1024);
    CPU cpu(mem);

    std::vector<uint8_t> program = {
        0x93, 0x00, 0x00, 0x01,  // addi x1, x0, 256
        0x13, 0x01, 0x01, 0x01   // addi x2, x2, 257
    };

    mem.loadProgram(program, 0);
    cpu.run(2);              // Run 2 instructions
    cpu.printRegisters();    // View register state

    return 0;
}
