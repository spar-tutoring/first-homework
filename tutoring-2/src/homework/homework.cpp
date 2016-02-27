#pragma once

#include "homework.hpp"

using namespace std;

std::function<bool(int)> relational_filter(int rel_num, const std::string &rel) {
    map<string, function<bool(int)>> filters{
        { "==", [rel_num](int el) { return el == rel_num; } },
        { "!=", [rel_num](int el) { return el != rel_num; } },
        { "<=", [rel_num](int el) { return el <= rel_num; } },
        { ">=", [rel_num](int el) { return el >= rel_num; } }
    };
    return filters.at(rel);
}

std::function<int(int)> arithmetic_predicate(int rel_num, char sym) {
    map<char, function<int(int)>> mods{
        { '+', [rel_num](int el) { return el + rel_num; } },
        { '-', [rel_num](int el) { return el - rel_num; } },
        { '*', [rel_num](int el) { return el * rel_num; } },
        { '/', [rel_num](int el) { return el / rel_num; } }
    };

    return mods.at(sym);
}

vector<int> homework(const vector<int> &input, int rel_num, string relation, char arithmetic_sym) {
    auto rel_func = relational_filter(rel_num, relation);
    auto filter = [rel_func](int el) { return !rel_func(el); };

    vector<int> data(input);

    data.erase(remove_if(begin(data), end(data), filter), end(data));

    auto mod_func = arithmetic_predicate(rel_num, arithmetic_sym);

    for_each(begin(data), end(data), [mod_func](int &el) {
        el = mod_func(el);
    });

    return data;
}