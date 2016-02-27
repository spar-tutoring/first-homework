#include "catch/catch.hpp"

#include "../homework.hpp"

TEST_CASE("Relational filters", "[relational_filter]") {
    SECTION("==") {
        auto filter = relational_filter(5, "==");
        REQUIRE(filter(5));
        REQUIRE_FALSE(filter(4));
        REQUIRE_FALSE(filter(6));
    }

    SECTION("!=") {
        auto filter = relational_filter(7, "!=");
        REQUIRE(filter(0));
        REQUIRE(filter(10));
        REQUIRE_FALSE(filter(7));
    }

    SECTION("<=") {
        auto filter = relational_filter(3, "<=");
        REQUIRE(filter(3));
        REQUIRE(filter(2));
        REQUIRE_FALSE(filter(4));
    }

    SECTION(">=") {
        auto filter = relational_filter(3, ">=");
        REQUIRE(filter(3));
        REQUIRE(filter(4));
        REQUIRE_FALSE(filter(2));
    }
}