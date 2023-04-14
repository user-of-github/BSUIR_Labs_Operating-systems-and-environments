#include <sys/wait.h>
#include "./shared/shared.hpp"

char *connect_to_shared_block();

void destroy_shared_block();

int main(int argc, char *argv[])
{
	const auto semaphore_id{try_get_semaphore_id(kSemaphoreId, "[Process 1] Error: can not get semaphore")};

	// text to send to child process via shared memory
	std::cout << "[Process 1] Type some message to put in shared memory" << '\n';
	std::string message{};
	std::getline(std::cin, message);

	char *shared_block{};

	// attach to shared memory and copy string to there, then detach
	shared_block = connect_to_shared_block();
	std::cout << "[Process 1] Writing to shared memory: " << message << '\n';
	strncpy(shared_block, message.c_str(), kBlockSize);
	detach_memory_block(shared_block);

	std::cout << "[Process 1] Launching (child) process 2 with transforming function" << '\n';

	semctl(semaphore_id, 0, SETVAL, 1); // set up semaphore block

	if (const auto process_id{fork()}; process_id == -1)
	{
		throw std::runtime_error("[Process 1] New process is not created");
	}
	else if (process_id == 0) // new child process
	{
		char *new_argv[]{NULL};
		execv("transform_app", new_argv);
	}
	else // this (parent) process
	{
		std::cout << "Press smth to unlock semaphore" << '\n';
		getchar();
		std::cout << '\n';

		int status{};
		semctl(semaphore_id, 0, SETVAL, 0); // cancel block

		waitpid(process_id, &status, 0);
		std::cout << "\n[Process 1] (Child) process 2 executed with status " << status << '\n';

		// attach again and check result
		shared_block = connect_to_shared_block();
		std::cout << "[Process 1] Received transformed message from shared memory: " << shared_block << '\n';

		detach_memory_block(shared_block);
		destroy_shared_block();

		try_remove_semaphore_array(semaphore_id, "[Process 1] Error: Can not remove semaphore");
	}

	return 0;
}

char *connect_to_shared_block()
{
	const auto response{attach_memory_block(kSharedBlockId, kBlockSize)};

	if (response == NULL)
	{
		throw std::runtime_error("[Process 1] Error: Can not get shared memory block");
		exit(1);
	}

	return response;
}

void destroy_shared_block()
{
	if (const auto successfully_removed{destroy_memory_block(kSharedBlockId)}; successfully_removed)
		std::cout << "[Process 1] Destroyed block " << kSharedBlockId << '\n';
	else
		std::cout << "[Process 1] Didn't destroy block " << kSharedBlockId << '\n';
}