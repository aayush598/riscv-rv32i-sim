CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/cpu.cpp src/instruction.cpp src/memory.cpp src/loader.cpp

TESTS = \
	tests/test_main.cpp \
	tests/test_register.cpp \
	tests/test_memory.cpp \
	tests/test_instruction.cpp \
	tests/test_fetch.cpp \
	tests/test_execute.cpp \
	tests/test_instruction_exec.cpp \
	tests/test_full_integration.cpp
	
TARGET = riscv_test

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SRC) $(TESTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^

test: $(TARGET)
	./$(TARGET)


clean:
	rm -f $(TARGET)
