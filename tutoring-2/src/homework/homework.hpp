#pragma once

#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
#include <iterator>
#include <vector>
#include <string>

std::function<bool(int)> relational_filter(int rel_num, const std::string &rel);
std::function<int(int)> arithmetic_predicate(int rel_num, char sym);

std::vector<int> homework(const std::vector<int> &input, int rel_num, std::string relation, char arithmetic_sym);