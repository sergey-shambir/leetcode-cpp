#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Own tests")
{
    Solution s;
    REQUIRE(s.intToRoman(1) == "I");
    REQUIRE(s.intToRoman(2) == "II");
    REQUIRE(s.intToRoman(3) == "III");
    REQUIRE(s.intToRoman(4) == "IV");
    REQUIRE(s.intToRoman(5) == "V");
    REQUIRE(s.intToRoman(6) == "VI");
    REQUIRE(s.intToRoman(7) == "VII");
    REQUIRE(s.intToRoman(8) == "VIII");
    REQUIRE(s.intToRoman(9) == "IX");
    REQUIRE(s.intToRoman(10) == "X");
    REQUIRE(s.intToRoman(11) == "XI");
    REQUIRE(s.intToRoman(12) == "XII");
    REQUIRE(s.intToRoman(30) == "XXX");
    REQUIRE(s.intToRoman(40) == "XL");
    REQUIRE(s.intToRoman(1900) == "MCM");
}

TEST_CASE("Examples from leetcode")
{
    Solution s;

    // Input: 58
    // Output: s = "LVIII"
    REQUIRE(s.intToRoman(58) == "LVIII");

    // Input: 1994
    // Output: s = "MCMXCIV"
    REQUIRE(s.intToRoman(1994) == "MCMXCIV");
}
