#include <unordered_set>
#include <cassert>
#include <vector>
#include <string>
#include <iostream>
#include "./errors_checker/errors_checker.hpp"


int main()
{
	const std::vector<std::string> dictionary_source{"test", "word", "example", "text"};
	const DictionaryType dictionary {create_full_dictionary(dictionary_source)};

	const std::pair<std::string, std::string> source_texts[]{
		{"Tesd text with wort", "test text with word"},
		{"Tesd text with Wort", "test text with word"},
		{"No errors, test, word, Example", "No errors, test, word, Example"}
	};

	for (const auto &[source, result] : source_texts) {
		const std::string corrected_text {get_corrected_text(source, dictionary)};
		assert(corrected_text == result);
		//std::cout << corrected_text << ' ' << result << '\n';
	}

	std::clog << "Tests passed" << '\n';

	return 0;
}