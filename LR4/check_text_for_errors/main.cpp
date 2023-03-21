#include <iostream>
#include "lib/include/data_reader.hpp"
#include "lib/include/errors_checker.hpp"


int main()
{
	const std::string kDictionaryFileName{"dictionary.txt"};
	const std::string kInputTextFileName{"text.txt"};

	const std::vector<std::string> source_dictionary{get_source_dictionary(kDictionaryFileName)};
	const std::string source_text{get_source_text(kInputTextFileName)};

	const DictionaryType dictionary{create_full_dictionary(source_dictionary)};

	for (const auto &[key, value] : dictionary) {
		//std::cout << key << ' ' << value << '\n';
	}

	const auto corrected_text{get_corrected_text(source_text, dictionary)};

	std::cout << corrected_text << '\n';

	return 0;
}
