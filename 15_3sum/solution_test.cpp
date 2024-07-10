#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;

vector<vector<int>> threeSum(vector<int> nums)
{
    Solution s;
    return s.threeSum(nums);
}

TEST_CASE("Examples from leetcode")
{
    // Input: nums = [-1,0,1,2,-1,-4]
    // Output: [[-1,-1,2],[-1,0,1]]
    REQUIRE_THAT(threeSum({ -1, 0, 1, 2, -1, -4 }), UnorderedEquals(vector<vector<int>>{ { -1, -1, 2 }, { -1, 0, 1 } }));

    // Input: nums = [0,1,1]
    // Output: []
    REQUIRE_THAT(threeSum({ 0, 1, 1 }), Equals(vector<vector<int>>{}));

    // Input: nums = [0,0,0]
    // Output: [[0,0,0]]
    REQUIRE_THAT(threeSum({ 0, 0, 0 }), Equals(vector<vector<int>>{ { 0, 0, 0 } }));
}

TEST_CASE("Own examples")
{
    REQUIRE_THAT(threeSum({ -1, 0, 1 }), Equals(vector<vector<int>>{ { -1, 0, 1 } }));
    REQUIRE_THAT(threeSum({ -1, -1, -1, 0, 0, 1, 1, 1 }), Equals(vector<vector<int>>{ { -1, 0, 1 } }));
    REQUIRE_THAT(threeSum({ -2, -1, -1, 0, 0, 1, 1, 1, 2 }), UnorderedEquals(vector<vector<int>>{ { -2, 1, 1 }, { -2, 0, 2 }, { -1, -1, 2 }, { -1, 0, 1 } }));
}
