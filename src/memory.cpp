#include "memory.h"
#include <iostream>
#include <iomanip>    

Memory::Memory(std::size_t size) : mem(size, 0), mem_size(size) {}

uint8_t Memory::read8(uint32_t addr) const {
    if (addr >= mem_size) throw std::out_of_range("Memory read8 out of bounds");
    return mem[addr];
}

uint16_t Memory::read16(uint32_t addr) const {
    return read8(addr) | (read8(addr + 1) << 8);
}

uint32_t Memory::read32(uint32_t addr) const {
    return read8(addr) | (read8(addr + 1) << 8) |
           (read8(addr + 2) << 16) | (read8(addr + 3) << 24);
}

void Memory::write8(uint32_t addr, uint8_t val) {
    if (addr >= mem_size) throw std::out_of_range("Memory write8 out of bounds");
    mem[addr] = val;
}

void Memory::write16(uint32_t addr, uint16_t val) {
    write8(addr, val & 0xFF);
    write8(addr + 1, (val >> 8) & 0xFF);
}

void Memory::write32(uint32_t addr, uint32_t val) {
    write8(addr, val & 0xFF);
    write8(addr + 1, (val >> 8) & 0xFF);
    write8(addr + 2, (val >> 16) & 0xFF);
    write8(addr + 3, (val >> 24) & 0xFF);
}

void Memory::loadProgram(const std::vector<uint8_t>& data, uint32_t startAddr) {
    if (startAddr + data.size() > mem_size)
        throw std::out_of_range("Program size exceeds memory bounds");

    std::copy(data.begin(), data.end(), mem.begin() + startAddr);
}

void Memory::dumpMemory(uint32_t start, uint32_t end) const {
    if (start >= mem_size || end > mem_size || start > end)
        throw std::out_of_range("Invalid memory dump range");

    std::cout << "\n==== MEMORY DUMP ====\n";
    for (uint32_t addr = start; addr < end; addr += 4) {
        std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << addr
                  << ": 0x" << std::setw(8) << std::setfill('0') << read32(addr) << "\n";
    }
}
