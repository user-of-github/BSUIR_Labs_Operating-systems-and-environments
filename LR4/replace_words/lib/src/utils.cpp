#include "../include/utils.hpp"


const std::string convert_to_lower_case(const std::string &source)
{
	std::string response{source};

	std::transform(
		std::begin(response),
		std::end(response),
		std::begin(response),
		[&](const auto &symbol) { return std::tolower(symbol); }
	);

	return response;
}