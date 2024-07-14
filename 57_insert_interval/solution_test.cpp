#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::UnorderedEquals;

namespace
{
vector<vector<int>> insert(vector<vector<int>> intervals, vector<int> newInterval)
{
    Solution s;
    return s.insert(intervals, newInterval);
}
} // namespace

TEST_CASE("Own examples")
{
    REQUIRE_THAT(insert({ { 1, 3 }, { 4, 5 }, { 7, 9 } }, { 4, 8 }), UnorderedEquals(vector<vector<int>>{ { 1, 3 }, {4, 9} }));

    REQUIRE_THAT(insert({ { 1, 3 }, { 4, 5 } }, { 4, 8 }), UnorderedEquals(vector<vector<int>>{ { 1, 3 }, {4, 8} }));

    REQUIRE_THAT(insert({ { 1, 3 }, { 4, 5 } }, { 4, 5 }), UnorderedEquals(vector<vector<int>>{ { 1, 3 }, {4, 5} }));

    REQUIRE_THAT(insert({ { 1, 3 }, { 4, 5 }, {7, 9} }, { 10, 15 }), UnorderedEquals(vector<vector<int>>{ { 1, 3 }, { 4, 5 }, {7, 9}, { 10, 15 } }));

    REQUIRE_THAT(insert({ { 1, 3 }, { 4, 5 }, {7, 9}, {10, 11} }, { 2, 10 }), UnorderedEquals(vector<vector<int>>{ { 1, 11 } }));
    REQUIRE_THAT(insert({ { 1, 3 }, { 4, 5 }, {7, 9}, {10, 11} }, { 2, 15 }), UnorderedEquals(vector<vector<int>>{ { 1, 15 } }));
    REQUIRE_THAT(insert({ { 2, 3 }, { 4, 5 }, {7, 9}, {10, 12} }, { 1, 12 }), UnorderedEquals(vector<vector<int>>{ { 1, 12 } }));
}
