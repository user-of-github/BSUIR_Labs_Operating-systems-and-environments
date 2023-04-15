#include <chrono>
#include "./sort_service.hpp"


int main()
{
	const std::size_t kArrayLength{14000000};
	const long long kMaxValue{10000000000};
	const long long kMinValue{-10000000000};

	const std::size_t kThreadsCount{7};
	const constexpr auto kBlocksCount{kThreadsCount}; // for usual merge sort in 1 thread

	if (kArrayLength % kThreadsCount != 0)
		throw std::invalid_argument("Array length is not multiple of threads count");


	std::cout.tie(NULL);

	const auto source_data{generate_random_array(kArrayLength, kMinValue, kMaxValue)};

	const auto is_sorted{[](const SortedArrayType &arr) -> bool { return std::is_sorted(std::cbegin(arr), std::cend(arr)); }};

	//print_array(data);
	std::cout << (is_sorted(source_data) ? "Initial array is sorted (fantastic...)" : "Initial array is not sorted") << '\n' << '\n';

	const auto start_execution_parallel{std::chrono::high_resolution_clock::now()};
	const auto sorted_data1{sort_array_in_parallel_threads(source_data, kThreadsCount)};
	std::cout << (is_sorted(sorted_data1) ? "Sorted" : "Not sorted") << '\n';
	const auto finish_execution_parallel{std::chrono::high_resolution_clock::now()};

	const auto parallel_execution_duration{std::chrono::duration_cast<std::chrono::milliseconds>(
		finish_execution_parallel - start_execution_parallel
	).count()};

	std::cout << "Parallel mode: " << parallel_execution_duration << " milliseconds" << '\n' << '\n';

	const auto start_execution_usual{std::chrono::high_resolution_clock::now()};
	const auto sorted_data2{sort_array_in_one_thread(source_data, kBlocksCount)};
	std::cout << (is_sorted(sorted_data2) ? "Sorted" : "Not sorted") << '\n';
	const auto finish_execution_usual{std::chrono::high_resolution_clock::now()};

	const auto usual_execution_duration{std::chrono::duration_cast<std::chrono::milliseconds>(
		finish_execution_usual - start_execution_usual
	).count()};

	std::cout << "Usual mode: " << usual_execution_duration << " milliseconds" << '\n' << '\n';

	//print_array(sorted_data1);
	//print_array(sorted_data2);

	return 0;
}

