#include "solution.h"

#include <catch2/catch_test_macros.hpp>

namespace {
    bool isPalindrome(int x)
    {
        Solution solution;
        return solution.isPalindrome(x);
    }
}

TEST_CASE("Examples from leetcode")
{
    REQUIRE(isPalindrome(121) == true);
    REQUIRE(isPalindrome(-121) == false);
    REQUIRE(isPalindrome(10) == false);
    REQUIRE(isPalindrome(11) == true);
    REQUIRE(isPalindrome(1000021) == false);
}