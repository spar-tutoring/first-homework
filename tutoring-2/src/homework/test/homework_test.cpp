#include "catch/catch.hpp"
#include "../homework.hpp"

#include <vector>
#include <string>

TEST_CASE("Integration", "[homework]") {
    

    SECTION("Sample") {
        std::vector<int> input = { 1, 2, 3, 4, 5 };
        std::string rel = "<=";
        int rel_num = 3;
        char arit_sym = '*';

        std::vector<int> required_output = { 3, 6, 9 };
        auto result = homework(input, rel_num, rel, arit_sym);
        REQUIRE(result == required_output);
    }
}