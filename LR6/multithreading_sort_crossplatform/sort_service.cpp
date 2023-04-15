#include "./sort_service.hpp"


const SortedArrayType generate_random_array(const std::size_t size, const long long min_value, const long long max_value)
{
	SortedArrayType response(size);

	std::srand(std::time(NULL));
	std::default_random_engine generator{};
	std::uniform_int_distribution<long long> distribution(min_value, max_value);
	auto random{[&distribution, &generator]() { return distribution(generator); }};

	for (auto &item : response)
		item = random();

	return response;
}

void sort_thread(SortedArrayType &sub_array)
{
	std::sort(std::begin(sub_array), std::end(sub_array));
}


const std::vector<SortedArrayType> split_array_into_sub_arrays(const SortedArrayType &source, const std::size_t blocks_count)
{
	const std::size_t items_per_block{source.size() / blocks_count};

	std::vector<SortedArrayType> sub_blocks{};
	sub_blocks.reserve(blocks_count);

	for (std::size_t block_number{0}; block_number < blocks_count; ++block_number)
	{
		const auto start{std::cbegin(source) + items_per_block * block_number};
		const auto end{std::cbegin(source) + block_number * items_per_block + items_per_block};
		sub_blocks.push_back(SortedArrayType(start, end));
	}

	return sub_blocks;
}

const SortedArrayType merge_sorted_arrays_into_one(const std::vector<SortedArrayType> &arrays)
{
	SortedArrayType response{};

	for (const auto &array : arrays)
	{
		SortedArrayType temp(response.size() + array.size());

		std::merge(
			std::begin(response), std::end(response),
			std::begin(array), std::cend(array),
			std::begin(temp)
		);

		response = std::move(temp);
	}

	return response;
}

const SortedArrayType sort_array_in_parallel_threads(const SortedArrayType &source, const std::size_t threads_count)
{
	std::vector<std::thread> threads{};
	threads.reserve(threads_count);

	auto sub_vectors{split_array_into_sub_arrays(source, threads_count)};

	for (auto &sub_array : sub_vectors) // splitting into threads
		threads.emplace_back(sort_thread, std::ref(sub_array));

	for (auto &thread : threads) // waiting for all
		thread.join();

	const auto response{merge_sorted_arrays_into_one(sub_vectors)};

	return response;
}

const SortedArrayType sort_array_in_one_thread(const SortedArrayType &source, const std::size_t blocks_count)
{
	std::vector<SortedArrayType> sub_vectors{split_array_into_sub_arrays(source, blocks_count)};

	for (auto &sub_vector : sub_vectors)
		sort_thread(sub_vector);

	const auto response{merge_sorted_arrays_into_one(sub_vectors)};

	return response;
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