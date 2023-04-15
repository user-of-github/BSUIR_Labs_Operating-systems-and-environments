#ifndef MULTITHREADING_SORT_CROSSPLATFORM__SORT_SERVICE_HPP_
#define MULTITHREADING_SORT_CROSSPLATFORM__SORT_SERVICE_HPP_

#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <random>


using SortedArrayType = std::vector<long long>;


const SortedArrayType generate_random_array(const std::size_t size);

void sort_thread(SortedArrayType &sub_array);

const SortedArrayType sort_array_in_parallel_threads(const SortedArrayType &source, const std::size_t threads_count);

void print_array(const SortedArrayType &array);

void print_sub_vectors(const std::vector<SortedArrayType> &);

#endif //MULTITHREADING_SORT_CROSSPLATFORM__SORT_SERVICE_HPP_
