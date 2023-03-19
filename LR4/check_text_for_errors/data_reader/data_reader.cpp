#include "./data_reader.hpp"


const std::vector<std::string> get_source_dictionary(const std::string &file_name)
{
	std::ifstream read {file_name};
	std::vector<std::string> response {};
	std::string temp {};

	while (read >> temp) {
		response.push_back(temp);
	}

	read.close();

	return response;
}

const std::string get_source_text(const std::string &file_name) {
	std::ifstream read{file_name};

	if (read.is_open()) {
		std::ostringstream ss{};
		ss << read.rdbuf();
		return ss.str();
	}

	return "";
}
