#include "./shared.hpp"



static const int get_shared_block(const char *filename, const int size){
    const auto key {ftok(filename, 0)};

    if (key == IPC_RESULT_ERROR) {
        return IPC_RESULT_ERROR;
    }

    // block should be greated if it does not exist
    // 0644 - something like permissions
    return shmget(key, size, 0644 | IPC_CREAT);
}

char * attach_memory_block(const char *filename,const int size)
{
    const int shared_block_id {get_shared_block(filename, size)};

    if (shared_block_id == IPC_RESULT_ERROR) {
        return NULL;
    }

    char *result {(char *)shmat(shared_block_id, NULL, 0)};
    

    if (result == (char *)IPC_RESULT_ERROR) {
        return NULL;
    }

    return result;
}

const bool detach_memory_block(const char *block) {
    return shmdt(block) != IPC_RESULT_ERROR;
}

const bool destroy_memory_block(const char *filename) {
    const int shared_block_id {get_shared_block(filename, 0)};

    if (shared_block_id == IPC_RESULT_ERROR) {
        return NULL;
    }

    // shmctl ==> actual destroying
    return shmctl(shared_block_id, IPC_RMID, NULL) != IPC_RESULT_ERROR;
}