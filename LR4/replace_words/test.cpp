#include <cassert>
#include <string>
#include "./convert_text/convert_text.hpp"


int main()
{
	using TestItem = std::pair<std::string, std::string>;

	const std::vector<std::string> vocabulary_source{"test1", "test2", "bbb", "ccc"};
	const std::unordered_set<std::string> vocabulary(std::cbegin(vocabulary_source), std::cend(vocabulary_source));

	const std::string kStringToChange{"A"};

	const TestItem test_items[] {
		{"test1 test test2", "A test A"},
		{"BBB CCC BC A", "A A BC A"},
		{"TEST2 test2 test1", "A A A"},
		{"BBB CCC BC A", "A A BC A"},
	};

	for (const auto &[source, result] : test_items) {
		const auto transformed{replace_words(source, vocabulary, kStringToChange)};
		assert(transformed == result);
	}

	std::clog << "Assertation passed\n";

	return 0;
}