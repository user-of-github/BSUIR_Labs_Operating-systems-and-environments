#include <iostream>
#include "./external_libs/include/data_reader.hpp"
#include "./external_libs/include/utils.hpp"
#include "./external_libs/include/errors_checker.hpp"


int main()
{
	const std::string kDictionaryFileName{"dictionary.txt"};
	const std::string kInputTextFileName{"text.txt"};

	const std::vector<std::string> source_dictionary{get_source_dictionary(kDictionaryFileName)};
	const std::string source_text{get_source_text(kInputTextFileName)};

	std::cout << source_text << '\n';

	return 0;
}
