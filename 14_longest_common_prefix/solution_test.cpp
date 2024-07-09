#include "solution.h"

#include <catch2/catch_test_macros.hpp>

string longestCommonPrefix(vector<string> strs)
{
    Solution s;
    return s.longestCommonPrefix(strs);
}

TEST_CASE("Own examples")
{
    REQUIRE(longestCommonPrefix({ "test", "tester", "testing" }) == "test");
    REQUIRE(longestCommonPrefix({ "testable", "tester", "testing" }) == "test");
    REQUIRE(longestCommonPrefix({ "a", "b", "c" }) == "");
    REQUIRE(longestCommonPrefix({ "apple", "banana", "cherry" }) == "");
    REQUIRE(longestCommonPrefix({ "cherry", "chair", "charlie" }) == "ch");
}
