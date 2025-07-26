#include "doctest.h"
#include "cpu.h"
#include "memory.h"
#include "loader.h"
#include <filesystem>
#include <iostream>

TEST_CASE("Full integration: Execute add_test.bin") {
    std::string binPath = "test_programs/add_test.bin";
    REQUIRE(std::filesystem::exists(binPath));

    // Load binary using your Loader class
    std::vector<uint8_t> binaryData;
    CHECK_NOTHROW(binaryData = Loader::loadBinaryFile(binPath));
    CHECK(!binaryData.empty());

    // Initialize memory and load data
    Memory memory(1024 * 64); // 64KB memory or any appropriate size

    uint32_t address = 0x00000000;
    for (uint8_t byte : binaryData) {
        memory.write8(address++, byte);
    }

    // Initialize and reset CPU
    CPU cpu(memory);
    cpu.reset();

    // Run a fixed number of instructions
    cpu.run(10); // You can increase this if needed

    // ✅ Assert expected register values (example: x5 = 10, x6 = 30)
    CHECK(cpu.getRegister(5) == 10);
    CHECK(cpu.getRegister(6) == 20);

    // Optional: Print registers for visual confirmation
    cpu.printRegisters();
}
