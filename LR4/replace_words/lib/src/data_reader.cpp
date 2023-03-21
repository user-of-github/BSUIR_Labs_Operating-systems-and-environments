#include "../include/data_reader.hpp"


const std::string read_text_from_file(const std::string &file_name)
{
	std::ifstream read{file_name};

	if (read.is_open()) {
		std::ostringstream ss{};
		ss << read.rdbuf();
		return ss.str();
	}

	return "";
}

const std::unordered_set<std::string> make_dictionary_of_forbidden_words(const std::string &file_name)
{
	std::unordered_set<std::string> response{};
	std::ifstream read{file_name};

	if (std::string temp{}; read.is_open()) {
		while (read >> temp) {
			const auto in_lowe_case{convert_to_lower_case(temp)};
			response.insert(in_lowe_case);
		}
	}

	return response;
}