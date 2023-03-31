#include <iostream>
#include "./external_libs/include/data_reader.hpp"
#include "./external_libs/include/utils.hpp"
#include "./external_libs/include/errors_checker.hpp"
#include "./external_libs/shared/convert_text.hpp"
#include "./external_libs/shared/utils.hpp"
#include "./external_libs/shared/data_reader.hpp"

int main()
{
	const std::string kDictionaryFileName{"dictionary.txt"};
	const std::string kInputTextFileName{"text.txt"};

	const std::vector<std::string> source_dictionary{get_source_dictionary(kDictionaryFileName)};
	const auto dictionary {create_full_dictionary(source_dictionary)};
	const std::string source_text{get_source_text(kInputTextFileName)};

	const std::string fixed_text {get_corrected_text(source_text, dictionary)};

	std::cout << fixed_text << '\n' << '\n';

	const std::string kCenshorshipDictionaryFileName{"words_to_change.txt"};
	const std::unordered_set<std::string> censorshipDictionary{make_dictionary_of_forbidden_words(kDictionaryFileName)};
	const std::string kStandardWordToInsert{"[REPLACED]"};

	const std::string transformed_text{replace_words(fixed_text, censorshipDictionary, kStandardWordToInsert)};

	std::cout << transformed_text << '\n' << '\n';
	return 0;
}
