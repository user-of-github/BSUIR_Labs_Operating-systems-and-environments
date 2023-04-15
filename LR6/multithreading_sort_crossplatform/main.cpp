#include "./sort_service.hpp"


int main()
{
	const std::size_t kArrayLength{30};
	const std::size_t kThreadsCount{5};

	if (kArrayLength % kThreadsCount != 0)
	{
		throw std::invalid_argument("Array length is not multiple of threads count");
	}

	SortedArrayType data{generate_random_array(kArrayLength)};

	const auto is_sorted{[](const SortedArrayType &arr) -> bool { return std::is_sorted(std::cbegin(arr), std::cend(arr)); }};

	//print_array(data);
	std::cout << (is_sorted(data) ? "Initial array is sorted" : "Initial array is not sorted") << '\n';

	const auto sorted_data {sort_array_in_parallel_threads(data, kThreadsCount)};

	//print_array(sorted_data);
	std::cout << (is_sorted(sorted_data) ? "Output data is sorted" : "Output data is not sorted") << '\n';

	return 0;
}

