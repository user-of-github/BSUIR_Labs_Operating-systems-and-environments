#include <chrono>
#include <tuple>
#include "./sort_service.hpp"


const std::tuple<const SortedArrayType, const long long> measure_time_of_sorting_function_executing(
	const auto &function_pointer,
	const SortedArrayType &data,
	const std::size_t second_arg
);

int main()
{
	const std::size_t kArrayLength{12000000};
	const long long kMaxValue{10000000000};
	const long long kMinValue{-10000000000};

	const std::size_t kThreadsCount{8};
	const constexpr auto kBlocksCount{kThreadsCount}; // for usual merge sort in 1 thread

	std::cout.tie(NULL);

	const auto source_data{generate_random_array(kArrayLength, kMinValue, kMaxValue)};
	const auto is_sorted{[](const SortedArrayType &arr) -> bool { return std::is_sorted(std::cbegin(arr), std::cend(arr)); }};

	//print_array(data);
	std::cout << (is_sorted(source_data) ? "Initial array is sorted (fantastic...)" : "Initial array is not sorted") << '\n' << '\n';

	const auto [sorted_data_with_threads, parallel_execution_duration] {
		measure_time_of_sorting_function_executing(sort_array_in_parallel_threads, source_data, kThreadsCount)
	};
	std::cout << (is_sorted(sorted_data_with_threads) ? "Sorted" : "Not sorted") << '\n';
	std::cout << "Parallel mode: " << parallel_execution_duration << " milliseconds" << '\n' << '\n';

	//print_array(sorted_data_with_threads);


	const auto [sorted_data_without_threads, usual_execution_duration] {
		measure_time_of_sorting_function_executing(sort_array_in_one_thread, source_data, kBlocksCount)
	};

	std::cout << (is_sorted(sorted_data_without_threads) ? "Sorted" : "Not sorted") << '\n';
	std::cout << "Usual mode: " << usual_execution_duration << " milliseconds" << '\n' << '\n';

	return 0;
}

const std::tuple<const SortedArrayType, const long long> measure_time_of_sorting_function_executing(
	const auto &function_pointer,
	const SortedArrayType &data,
	const std::size_t second_arg
)
{
	const auto start_execution{std::chrono::high_resolution_clock::now()};
	const auto sorted_data{function_pointer(data, second_arg)};

	const auto finish_execution{std::chrono::high_resolution_clock::now()};

	const auto execution_duration{std::chrono::duration_cast<std::chrono::milliseconds>(finish_execution - start_execution).count()};

	return std::make_tuple(std::move(sorted_data), execution_duration);
}