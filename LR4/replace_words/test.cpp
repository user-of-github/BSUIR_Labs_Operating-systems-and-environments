#include <cassert>
#include <string>
#include <array>
#include "./data_reader.hpp"
#include "./convert_text.hpp"


int main()
{
	const std::vector<std::string> vocabulary_source {"test1", "test2",  "BBB", "CCC"};
	const std::unordered_set<std::string> vocabulary (std::cbegin(vocabulary_source), std::cend(vocabulary_source));

	const std::string kStringToChange {"A"};

	const std::array<std::pair<std::string, std::string>, 2> test_items{
		std::make_pair<std::string, std::string>("test1 test test2", "A test A"),
		std::make_pair<std::string, std::string>("BBB CCC BC A", "A A BC A")
	};

	for (const auto &[source, result] : test_items) {
		const auto transformed {replace_words(source, vocabulary, kStringToChange)};
		std::cout << source << '|' << transformed << '|' << result << '\n';
		assert(transformed == result);
	}
	return 0;
}