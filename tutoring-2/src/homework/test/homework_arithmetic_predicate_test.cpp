#include "catch/catch.hpp"

#include "../homework.hpp"

TEST_CASE("Arithemtic predicate", "[arithmetic_predicate]") {
    SECTION("+") {
        auto add2 = arithmetic_predicate(2, '+');
        REQUIRE(add2(3) == 5);
        REQUIRE(add2(8) == 10);
    }

    SECTION("-") {
        auto sub3 = arithmetic_predicate(3, '-');
        REQUIRE(sub3(6) == 3);
        REQUIRE(sub3(0) == -3);
    }

    SECTION("*") {
        auto mul4 = arithmetic_predicate(4, '*');
        REQUIRE(mul4(4) == 16);
        REQUIRE(mul4(-4) == -16);
    }

    SECTION("/") {
        auto div2 = arithmetic_predicate(2, '/');
        REQUIRE(div2(4) == 2);
        REQUIRE(div2(-8) == -4);
    }
}