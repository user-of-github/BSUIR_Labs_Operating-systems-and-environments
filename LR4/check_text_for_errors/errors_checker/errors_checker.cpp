#include "./errors_checker.hpp"


const DictionaryType create_full_dictionary(const std::vector<std::string> &source)
{
	DictionaryType response {};

	for (const auto &word : source) {
		auto lowered_case_word {word};
		const auto correct_lowered_case_word {lowered_case_word};

		response.insert({correct_lowered_case_word, correct_lowered_case_word});

		for (std::size_t index {0}; index < lowered_case_word.length(); ++index) {
			const char current_symbol {lowered_case_word.at(index)};

			lowered_case_word.at(index) = kAnySymbol;

			response.insert({lowered_case_word, correct_lowered_case_word});

			lowered_case_word.at(index) = current_symbol;
		}
	}

	return response;
}

const std::string get_corrected_text(const std::string &source_text, const DictionaryType &dictionary)
{
	std::string response {source_text};
	std::istringstream word_stream {response};
	std::string word {};

	const auto get_word_start_index{[&](const std::size_t end, const ::std::size_t length) -> std::size_t {
	  if (end == -1) {
		  return source_text.length() - length;
	  }
	  return end - length;
	}};

	while (word_stream >> word) {
		const std::string lowered {convert_to_lower_case(word)};

		if (dictionary.count(lowered)) {
			continue;
		}

		const long long word_end{word_stream.tellg()};
		const std::size_t word_length{word.length()};
		const std::size_t word_start{get_word_start_index(word_end, word_length)};

		for (std::size_t index {0}; index < lowered.length(); ++index) {
			std::string temp {lowered};
			temp.at(index) = kAnySymbol;

			if (dictionary.count(temp)) {
				response.replace(word_start, word_length, dictionary.at(temp));
				break;
			}
		}
	}

	return response;
}