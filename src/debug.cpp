#include "debug.h"
#include <iostream>

void runDebugger(CPU& cpu) {
    std::string cmd;
    std::cout << "Debugger started. Enter 'step', 'run', 'regs', or 'exit'.\n";

    while (true) {
        std::cout << "debug> ";
        std::cin >> cmd;

        if (cmd == "step") {
            cpu.step();  // executes 1 instruction
        } else if (cmd == "run") {
            cpu.run(100);  // runs 100 instructions (or choose any number)
        } else if (cmd == "regs") {
            cpu.printRegisters();
        } else if (cmd == "exit") {
            break;
        } else {
            std::cout << "Unknown command.\n";
        }
    }
}
