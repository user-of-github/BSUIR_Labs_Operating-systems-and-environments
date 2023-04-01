#include <iostream>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include "./shared/shared.hpp"


char *connect_to_shared_block();

void destroy_shared_block();


int main(int argc, char *argv[])
{
    // text to send to child process via shared memory
    std::cout << "[Parent] Type message to put in shared memory" << '\n';
    std::string message{};
    std::getline(std::cin, message);

    char *shared_block;

    // attach to shared memory and copy string to there, then detach
    shared_block = connect_to_shared_block();
    std::cout << "[Parent] Writing to shared memory: " << message << '\n';
    strncpy(shared_block, message.c_str(), kBlockSize);
    detach_memory_block(shared_block);


    std::cout << "[Parent] Launching child process with transforming function" << '\n';

    if (const auto process_id {fork()}; process_id == -1) 
    {
        throw std::runtime_error("[Parent] New process is not created");
        exit(1);
    } 
    else if (int status {}; process_id > 0) 
    {
        waitpid(process_id, &status, 0);
        std::cout << "[Parent] Child process executed" << '\n';

        // attach again and check result
        shared_block = connect_to_shared_block();
        std::cout << "[Parent] Received transformed message from shared memory: " << shared_block << '\n';

        detach_memory_block(shared_block);
    }
    else 
    {
        char *new_argv[] = { NULL };
        char *new_environment[] = { NULL };
        
        execve("transform_app", new_argv, new_environment);
    }


    return 0;
}


char *connect_to_shared_block()
{
    const auto response{attach_memory_block(kFileName, kBlockSize)};

    if (response == NULL) 
    {
        throw std::runtime_error("[Parent] Error: Can not get shared memory block");
        exit(1);
    }

    return response;
}

void destroy_shared_block() 
{
    if (const auto successfully_removed{destroy_memory_block(kFileName)}; successfully_removed)
        std::cout << "[Parent] Destroyed block " << kFileName << '\n';
    else
        std::cout << "[Parent] Didn't destroy block " << kFileName << '\n';
}