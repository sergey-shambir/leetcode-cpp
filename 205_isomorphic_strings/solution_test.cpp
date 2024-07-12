#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Own cases")
{
    Solution s;
    REQUIRE(s.isIsomorphic("", ""));
    REQUIRE(s.isIsomorphic("dog", "dog"));
    REQUIRE(s.isIsomorphic("dog", "cat"));

    REQUIRE(!s.isIsomorphic("dog", "egg"));
    REQUIRE(!s.isIsomorphic("dog", "elephant"));
    REQUIRE(!s.isIsomorphic("banana", "cherry"));
    REQUIRE(!s.isIsomorphic("merry", "cherry"));
    REQUIRE(!s.isIsomorphic("merry", "daddy"));
    REQUIRE(s.isIsomorphic("merry", "buddy"));
}
