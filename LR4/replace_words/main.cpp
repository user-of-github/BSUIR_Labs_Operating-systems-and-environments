#include <iostream>
#include "./file_reader.hpp"

int main()
{
	const std::string kFileInputName {"input.txt"};
	const auto input_data {read_text_from_file(kFileInputName)};
	std::cout << input_data;
	return 0;
}
