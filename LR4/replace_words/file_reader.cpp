#include "./file_reader.hpp"

const std::string read_text_from_file(const std::string &file_name)
{
	std::ifstream read{file_name};

	if (read.is_open())
	{
		std::ostringstream ss {};
		ss << read.rdbuf();
		return ss.str();
	}

	return "";
}
