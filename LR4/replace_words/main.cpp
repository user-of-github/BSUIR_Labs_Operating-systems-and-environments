#include <iostream>
#include "./data_reader/data_reader.hpp"
#include "./convert_text/convert_text.hpp"


int main()
{
	const std::string kTextFileName{"input_text.txt"};
	const std::string kDictionaryFileName{"words_to_change.txt"};
	const std::string kStandardWordToInsert{"[REPLACED]"};

	const std::string input_text{read_text_from_file(kTextFileName)};
	const std::unordered_set<std::string> dictionary{make_dictionary_of_forbidden_words(kDictionaryFileName)};

	const std::string transformed_text{replace_words(input_text, dictionary, kStandardWordToInsert)};

	std::cout << "Initial Text: " << '\n' << input_text << '\n' << "______________________" << '\n';
	std::cout << "Transformed Text: " << '\n' << transformed_text << '\n';

	return 0;
}
