#include "./shared/shared.hpp"
#include <iostream>


int main(int argc, char *argv[]) {
    const char *block {attach_memory_block(kFileName, kBlockSize)};

    if (block == NULL) {
        throw std::runtime_error("Second: Error: Cen not get block");
        return -1;
    }

    std::cout << "Reading " << block << '\n';

    detach_memory_block(block);

    return 0;
}