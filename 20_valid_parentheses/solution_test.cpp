#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Own examples")
{
    Solution sol;
    REQUIRE(sol.isValid(""));
    REQUIRE(sol.isValid("{}"));
    REQUIRE(sol.isValid("({})"));
    REQUIRE(sol.isValid("[]({})[[{()}]]"));

    REQUIRE(!sol.isValid("{"));
    REQUIRE(!sol.isValid("{"));
    REQUIRE(!sol.isValid("({])"));
    REQUIRE(!sol.isValid("((])"));
    REQUIRE(!sol.isValid("(()])"));
    REQUIRE(!sol.isValid("[]({})[{()}]]"));
    REQUIRE(!sol.isValid("[]({})[[{()}]"));
}
