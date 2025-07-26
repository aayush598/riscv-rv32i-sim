#include "cpu.h"
#include "memory.h"
#include <fstream>
#include <iostream>

std::vector<uint8_t> loadBinaryFile(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) throw std::runtime_error("Failed to open binary file");

    return std::vector<uint8_t>(std::istreambuf_iterator<char>(file), {});
}

int main() {
    constexpr uint32_t MEM_SIZE = 1 << 20;        // 1 MB
    constexpr uint32_t START_ADDR = 0x10000;      // Match RARS base

    Memory mem(MEM_SIZE);
    std::vector<uint8_t> program = loadBinaryFile("../test_programs/add_test.bin");
    mem.loadProgram(program, START_ADDR);

    CPU cpu(mem);
    cpu.setPC(START_ADDR);

    std::cout << "Instruction Fetch Test:\n";
    for (size_t i = 0; i < program.size(); i += 4) {
        uint32_t instr = cpu.fetch();
        std::cout << "Fetched 0x" << std::hex << instr << "\n";
    }

    return 0;
}
