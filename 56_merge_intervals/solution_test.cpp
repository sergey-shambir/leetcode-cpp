#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::UnorderedEquals;

namespace
{
vector<vector<int>> merge(vector<vector<int>> intervals)
{
    Solution s;
    return s.merge(intervals);
}
} // namespace

TEST_CASE("Leetcode examples")
{
    // Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    // Output: [[1,6],[8,10],[15,18]]
    REQUIRE_THAT(merge({{1, 3}, {2, 6}, {8, 10}, {15, 18}}), UnorderedEquals(vector<vector<int>>{{1, 6}, {8, 10}, {15, 18}}));

    // Input: intervals = [[1,4],[4,5]]
    // Output: [[1,5]]
    REQUIRE_THAT(merge({{1, 4}, {4, 5}}), UnorderedEquals(vector<vector<int>>{{1, 5}}));
}

TEST_CASE("Own examples")
{
    REQUIRE_THAT(merge({{2, 3}, {12, 14}, {1, 10}, {4, 5}}), UnorderedEquals(vector<vector<int>>{{1, 10}, {12, 14}}));
}
