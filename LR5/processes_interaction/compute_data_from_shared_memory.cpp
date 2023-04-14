#include <algorithm>
#include "./shared/shared.hpp"


void wait_for_semaphore(const int semaphore_id, const std::size_t sleep_time);

int main()
{
	const auto semaphore_id{try_get_semaphore_id(kSemaphoreId, "[Process 2] Error: can not get semaphore")};

	wait_for_semaphore(semaphore_id, 2);

	const auto block{attach_memory_block(kSharedBlockId, kBlockSize)};

	if (block == NULL)
	{
		throw std::runtime_error("[Process 2] Error: Can not get block");
		return -1;
	}

	const std::string data{block};

	std::cout << "[Process 2] Reading from shared memory: " << block << '\n';

	auto transformed{data};

	sleep(5); // to simulate long operation

	std::reverse(std::begin(transformed), std::end(transformed));

	std::cout << "[Process 2] I changed data in some way: " << transformed << '\n';
	strncpy(block, transformed.c_str(), kBlockSize);

	detach_memory_block(block);

	return 0;
}

void wait_for_semaphore(const int semaphore_id, const std::size_t sleep_time)
{
	while (true)
	{
		std::cout << "[Process 2] Memory block access is blocked by semaphore. Checking semaphore block" << '\n';
		const auto semaphore_check_result{semctl(semaphore_id, 0, GETVAL, 0)};

		if (!semaphore_check_result)
		{
			break;
		}

		sleep(sleep_time);
	}
}