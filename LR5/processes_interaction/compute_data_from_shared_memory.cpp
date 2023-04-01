#include <iostream>
#include <algorithm>
#include <unistd.h>
#include "./shared/shared.hpp"


int main(int argc, char *argv[])
{
    const auto block{attach_memory_block(kFileName, kBlockSize)};

    if (block == NULL)
    {
        throw std::runtime_error("[Process 2] Error: Can not get block");
        return -1;
    }

    const std::string data{block};

    std::cout << "[Process 2] Reading from shared memory: " << block << '\n';

    auto transformed{data};

    sleep(3); // to simulate long operation


    std::reverse(std::begin(transformed), std::end(transformed));

    std::cout << "[Process 2] I changed data in some way: " << transformed << '\n';
    strncpy(block, transformed.c_str(), kBlockSize);

    detach_memory_block(block);


    return 0;
}