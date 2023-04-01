#include "./shared/shared.hpp"
#include <iostream>


int main(int argc, char *argv[]) {
    std::string message {};
    std::cout << "Type message to put in shared memory" << '\n';
    
    std::getline(std::cin, message);

    char *shared_block {attach_memory_block(kFileName, kBlockSize)};

    if (shared_block == NULL) {
        throw std::runtime_error("First: Error: Can not get shared memory block");
        return -1;
    }


    std::cout << "Writing: " << message.c_str() << '\n';

    strncpy(shared_block, message.c_str(), kBlockSize);

    detach_memory_block(shared_block);

    return 0;
}