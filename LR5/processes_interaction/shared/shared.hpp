#pragma once

#ifndef SHARED_HPP
#define SHARED_HPP

#include <cstdbool>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


const auto kFileName {"somefilename"};

const auto kBlockSize {4096};

const auto IPC_RESULT_ERROR {-1};


char * attach_memory_block(const char *filename,const int size);

const bool detach_memory_block(const char *block);

const bool destroy_memory_block(const char *filename);


#endif /* SHARED_HPP */

