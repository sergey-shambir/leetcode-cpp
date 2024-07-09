#include "solution.h"

#include <catch2/catch_test_macros.hpp>

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
TEST_CASE("1st example from leetcode")
{
    Solution s;
    REQUIRE(s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
}

TEST_CASE("2nd example from leetcode")
{
    Solution s;
    REQUIRE(s.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
}

TEST_CASE("3rd example from leetcode")
{
    Solution s;
    REQUIRE(s.convert("A", 1) == "A");
}
