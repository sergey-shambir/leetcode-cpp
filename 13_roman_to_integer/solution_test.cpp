#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Own tests")
{
    Solution s;
    REQUIRE(s.romanToInt("I") == 1);
    REQUIRE(s.romanToInt("II") == 2);
    REQUIRE(s.romanToInt("III") == 3);
    REQUIRE(s.romanToInt("IV") == 4);
    REQUIRE(s.romanToInt("V") == 5);
    REQUIRE(s.romanToInt("VI") == 6);
    REQUIRE(s.romanToInt("VII") == 7);
    REQUIRE(s.romanToInt("VIII") == 8);
    REQUIRE(s.romanToInt("IX") == 9);
    REQUIRE(s.romanToInt("X") == 10);
    REQUIRE(s.romanToInt("XI") == 11);
    REQUIRE(s.romanToInt("XII") == 12);
    REQUIRE(s.romanToInt("XXX") == 30);
    REQUIRE(s.romanToInt("XL") == 40);
    REQUIRE(s.romanToInt("MCM") == 1900);
}

TEST_CASE("Examples from leetcode")
{
    Solution s;

    // Input: s = "LVIII"
    // Output: 58
    REQUIRE(s.romanToInt("LVIII") == 58);

    // Input: s = "MCMXCIV"
    // Output: 1994
    REQUIRE(s.romanToInt("MCMXCIV") == 1994);
}
