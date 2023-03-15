#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_set>
#include "./utils.hpp"


const std::string read_text_from_file(const std::string &);

const std::unordered_set<std::string> make_dictionary_of_forbidden_words(const std::string &);