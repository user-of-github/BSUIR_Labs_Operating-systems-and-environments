#ifndef CHECK_TEXT_FOR_ERRORS_ERRORS_CHECKER_ERRORS_CHECKER_HPP_
#define CHECK_TEXT_FOR_ERRORS_ERRORS_CHECKER_ERRORS_CHECKER_HPP_

#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "utils.hpp"


const char kAnySymbol{'*'};

using DictionaryType = std::unordered_map<std::string, std::string>;

const DictionaryType create_full_dictionary(const std::vector<std::string> &);

const std::string get_corrected_text(const std::string &, const DictionaryType &);

#endif //CHECK_TEXT_FOR_ERRORS_ERRORS_CHECKER_ERRORS_CHECKER_HPP_
