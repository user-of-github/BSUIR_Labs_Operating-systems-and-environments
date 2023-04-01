#include "./shared/shared.hpp"
#include <iostream>


int main(int argc, char *argv[]) {
    if (argc != 1) {
        throw std::invalid_argument("Wrong argument");
        return -1;
    }

    const auto response {destroy_memory_block(kFileName)};

    if (response) {
        std::cout << "Destroyed block " << kFileName << '\n';
    } else {
        std::cout << "Didn't destroy block " << kFileName << '\n';
    }

    return 0;
}