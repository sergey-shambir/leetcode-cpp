#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Examples from leetcode")
{
    Solution s;

    REQUIRE(s.isPalindrome("A man, a plan, a canal: Panama"));
    REQUIRE(!s.isPalindrome("race a car"));
    REQUIRE(s.isPalindrome(" "));
}
