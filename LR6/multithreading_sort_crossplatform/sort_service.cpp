#include "./sort_service.hpp"


const SortedArrayType generate_random_array(const std::size_t size)
{
	static const auto kMaxValue{100};
	static const auto kMinValue{-100};

	SortedArrayType response(size);

	std::srand(std::time(NULL));
	std::default_random_engine generator{};
	std::uniform_int_distribution<long long> distribution(kMinValue, kMaxValue);
	auto random{[&distribution, &generator]() { return distribution(generator); }};

	for (auto &item : response)
		item = random();

	return response;
}

void sort_thread(SortedArrayType &sub_array)
{
	std::sort(std::begin(sub_array), std::end(sub_array));
}

void print_array(const SortedArrayType &array)
{
	for (const auto &item : array)
		std::cout << item << ' ';

	std::cout << '\n';
}

void print_sub_vectors(const std::vector<SortedArrayType> &sub_vectors)
{
	for (std::size_t counter{0}; const auto &sub_vector : sub_vectors)
	{
		std::cout << "Subvector " << counter++ + 1 << ": ";
		print_array(sub_vector);
	}
}

const SortedArrayType sort_array_in_parallel_threads(const SortedArrayType &source, const std::size_t threads_count)
{
	const std::size_t items_per_thread{source.size() / threads_count};

	std::vector<std::thread> threads{};
	threads.reserve(threads_count);
	std::vector<SortedArrayType> sub_vectors_common{};

	sub_vectors_common.clear();
	sub_vectors_common.shrink_to_fit();
	sub_vectors_common.reserve(threads_count);

	// splitting into blocks
	for (std::size_t thread_number{0}; thread_number < threads_count; ++thread_number)
	{
		const auto start{std::cbegin(source) + items_per_thread * thread_number};
		const auto end{std::cbegin(source) + thread_number * items_per_thread + items_per_thread};
		SortedArrayType sub_vector(start, end);
		sub_vectors_common.push_back(sub_vector);
	}
	/*std::cout << "\nINITIAL SUB-VECTORS:\n" << '\n';
	print_sub_vectors(sub_vectors_common); */

	// splitting into threads
	for (auto &sub_array : sub_vectors_common)
		threads.emplace_back(sort_thread, std::ref(sub_array));

	// waiting for all
	for (auto &thread : threads)
		thread.join();

	/*std::cout << "\nSORTED SUB-VECTORS:\n" << '\n';
	print_sub_vectors(sub_vectors_common); */

	SortedArrayType response{};

	for (const auto &sorted_sub_vector : sub_vectors_common)
	{
		SortedArrayType temp(response.size() + sorted_sub_vector.size());

		std::merge(
			std::begin(response), std::end(response),
			std::begin(sorted_sub_vector), std::cend(sorted_sub_vector),
			std::begin(temp)
		);

		response = std::move(temp);
	}

	return response;
}