#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Own tests")
{
    Solution s;
    REQUIRE(s.strStr("hello world", "hello") == 0);
    REQUIRE(s.strStr("hello world", "world") == 6);
    REQUIRE(s.strStr("hello world", " world") == 5);
    REQUIRE(s.strStr("hello world", "") == 0);
    REQUIRE(s.strStr("world", "hello world") == -1);
    REQUIRE(s.strStr("cat", "dog") == -1);
    REQUIRE(s.strStr("hotdog", "dog") == 3);
}
