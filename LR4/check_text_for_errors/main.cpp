#include <iostream>
#include "./data_reader/data_reader.hpp"
#include "./errors_checker/errors_checker.hpp"


int main()
{
	const std::string kDictionaryFileName {"dictionary.txt"};
	const std::string kInputTextFileName {"text.txt"};

	const std::vector<std::string> source_dictionary {get_source_dictionary(kDictionaryFileName)};
	const std::string source_text {get_source_text(kInputTextFileName)};

	const DictionaryType dictionary {create_full_dictionary(source_dictionary)};

	const auto corrected_text {get_corrected_text(source_text, dictionary)};

	std::cout << corrected_text << '\n';


	return 0;
}
