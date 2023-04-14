#pragma once

#ifndef SHARED_HPP
#define SHARED_HPP

#include <iostream>
#include <cstdbool>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <stdexcept>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/shm.h>


const auto kSharedBlockId{"shared-memory-file-id"}; // must be the same as file name in the root

const auto kBlockSize{4096};

const auto IPC_RESULT_ERROR{-1};

const auto kSemaphoreId{2022};

char *attach_memory_block(const char *block_id, const int size);

const bool detach_memory_block(const char *block);

const bool destroy_memory_block(const char *block_id);

const int try_get_semaphore_id(const int id, const char *error_message);

void try_remove_semaphore_array(const int semaphore_id, const std::string &error_message);


#define SEMAPHORE_PERMISSIONS 0666

#endif /* SHARED_HPP */
