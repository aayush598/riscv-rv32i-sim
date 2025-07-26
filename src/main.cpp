#include "cpu.h"
#include "memory.h"
#include "loader.h"
#include "debug.h"
#include <iostream>


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <binary_file>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::vector<uint8_t> binary = Loader::loadBinaryFile(filename);

    Memory memory(1024 * 1024); // 1MB memory
    for (size_t i = 0; i < binary.size(); ++i) {
        memory.write8(0x00000000 + i, binary[i]);
    }


    CPU cpu(memory);
    cpu.reset();
    cpu.setPC(0x00000000);

    runDebugger(cpu);  // 👈 Start debugger loop

    return 0;
}
