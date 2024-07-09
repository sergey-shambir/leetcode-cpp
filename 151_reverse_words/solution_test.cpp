#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Own examples")
{
    Solution s;
    REQUIRE(s.reverseWords("") == "");
    REQUIRE(s.reverseWords("hello") == "hello");
    REQUIRE(s.reverseWords("hello world") == "world hello");
    REQUIRE(s.reverseWords("  hello world") == "world hello");
    REQUIRE(s.reverseWords("  hello   world  ") == "world hello");
}

