#include <iostream>
#include "cpu.h"

int main() {
    CPU cpu;

    cpu.reset();
    std::cout << "After reset:\n";
    cpu.printRegisters();

    std::cout << "\nSetting x1 = 0x12345678\n";
    cpu.setRegister(1, 0x12345678);
    cpu.printRegisters();

    std::cout << "\nTrying to set x0 = 0xFFFFFFFF (should remain 0)\n";
    cpu.setRegister(0, 0xFFFFFFFF);
    cpu.printRegisters();

    return 0;
}
