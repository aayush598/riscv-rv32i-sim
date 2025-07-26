#pragma once
#include <string>
#include <vector>
#include <cstdint>

class Loader {
public:
    static std::vector<uint8_t> loadBinaryFile(const std::string& filename);
};
