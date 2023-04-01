#include <iostream>
#include <algorithm>
#include <unistd.h>
#include "./shared/shared.hpp"


int main(int argc, char *argv[])
{
    char *block{attach_memory_block(kFileName, kBlockSize)};

    if (block == NULL)
    {
        throw std::runtime_error("Second: Error: Cen not get block");
        return -1;
    }

    const std::string data{block};

    std::cout << "[Child] Reading: " << block << '\n';

    std::string transformed{data};

    sleep(3); // JUST TO SIMULATE HARD WORK IN THIS SEPARATE PROCESS


    std::reverse(std::begin(transformed), std::end(transformed));

    std::cout << "[Child] Changed data in some way: " << transformed << '\n';
    strncpy(block, transformed.c_str(), kBlockSize);

    detach_memory_block(block);


    return 0;
}