#ifndef MULTITHREADING_SORT_CROSSPLATFORM__SORT_SERVICE_HPP_
#define MULTITHREADING_SORT_CROSSPLATFORM__SORT_SERVICE_HPP_

#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <random>


using SortedArrayType = std::vector<long long>;


const SortedArrayType generate_random_array(const std::size_t size, const long long min_value, const long long max_value);

void sort_thread(SortedArrayType &sub_array);

const std::vector<SortedArrayType> split_array_into_sub_arrays(const SortedArrayType &source, const std::size_t blocks_count);

const SortedArrayType merge_sorted_arrays_into_one(const std::vector<SortedArrayType> &arrays);

const SortedArrayType sort_array_in_parallel_threads(const SortedArrayType &source, const std::size_t threads_count);

const SortedArrayType sort_array_in_one_thread(const SortedArrayType &source, const std::size_t blocks_count);

void print_array(const SortedArrayType &array);

void print_sub_vectors(const std::vector<SortedArrayType> &);


#endif //MULTITHREADING_SORT_CROSSPLATFORM__SORT_SERVICE_HPP_
