#include "./sort_service.hpp"
#include <chrono>


int main()
{
	const std::size_t kArrayLength{30000000};
	const std::size_t kThreadsCount{10};
	const constexpr auto kBlocksCount {kThreadsCount}; // for usual merge sort in 1 thread

	if (kArrayLength % kThreadsCount != 0)
	{
		throw std::invalid_argument("Array length is not multiple of threads count");
	}

	SortedArrayType source_data{generate_random_array(kArrayLength)};

	const auto is_sorted{[](const SortedArrayType &arr) -> bool { return std::is_sorted(std::cbegin(arr), std::cend(arr)); }};

	//print_array(data);
	std::cout << (is_sorted(source_data) ? "Initial array is sorted" : "Initial array is not sorted") << '\n';


	const auto start_execution_parallel{std::chrono::high_resolution_clock::now()};
	const auto sorted_data1{sort_array_in_parallel_threads(source_data, kThreadsCount)};
	const auto finish_execution_parallel{std::chrono::high_resolution_clock::now()};

	const auto parallel_execution_duration{std::chrono::duration_cast<std::chrono::milliseconds>(
		finish_execution_parallel - start_execution_parallel
	).count()};

	std::cout << "Parallel mode: " << parallel_execution_duration << " milliseconds" << '\n';


	const auto start_execution_usual{std::chrono::high_resolution_clock::now()};
	const auto sorted_data2{sort_array_in_one_thread(source_data, kBlocksCount)};
	const auto finish_execution_usual{std::chrono::high_resolution_clock::now()};

	const auto usual_execution_duration{std::chrono::duration_cast<std::chrono::milliseconds>(
		finish_execution_usual - start_execution_usual
	).count()};

	std::cout << "Usual mode: " << usual_execution_duration << " milliseconds" << '\n';

	return 0;
}

