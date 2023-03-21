#include "../include/convert_text.hpp"


const std::string replace_words(const std::string &initial_text,
								const std::unordered_set<std::string> &vocabulary,
								const std::string &to_insert)
{
	const auto inserted_word_length{to_insert.length()};
	long long shift{0};

	std::string response{initial_text};

	std::istringstream words_stream{initial_text};

	std::string word{};

	const auto get_word_start_index{[&](const std::size_t end, const ::std::size_t length) -> std::size_t {
	  if (end == -1) {
		  return initial_text.length() - length;
	  }
	  return end - length;
	}};

	while (words_stream >> word) {
		if (const std::string lowered{convert_to_lower_case(word)}; vocabulary.count(lowered)) {

			const long long word_end{words_stream.tellg()};
			const std::size_t word_length{word.length()};
			const std::size_t word_start{get_word_start_index(word_end, word_length)};

			//std::cout << word << ' ' << word_start << ' ' << word_end << '\n';

			response.replace(word_start + shift, word_length, to_insert);
			shift += (static_cast<long long>(inserted_word_length) - static_cast<long long>(word_length));
			//std::cout << "RESPONSE: " << '\n' << response << '\n' << '\n';
		}
	}

	return response;
}