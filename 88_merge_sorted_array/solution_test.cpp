#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;

vector<int> merge(vector<int> nums1, vector<int> nums2)
{
    Solution s;
    const int size1 = int(nums1.size());
    const int size2 = int(nums2.size());

    vector<int> result(size1 + size2, 0xDEADBEEF);
    std::copy(nums1.begin(), nums1.end(), result.begin());

    s.merge(result, size1, nums2, size2);

    return result;
}

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
TEST_CASE("First example from leetcode")
{
    vector<int> nums1 = { 1, 2, 3 };
    vector<int> nums2 = { 2, 5, 6 };
    REQUIRE_THAT(merge(nums1, nums2), Equals<int>({ 1, 2, 2, 3, 5, 6 }));
    REQUIRE_THAT(merge(nums2, nums1), Equals<int>({ 1, 2, 2, 3, 5, 6 }));
}

// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
TEST_CASE("Second example from leetcode")
{
    vector<int> nums1 = { 1 };
    vector<int> nums2 = {};
    REQUIRE_THAT(merge(nums1, nums2), Equals<int>({ 1 }));
}

// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
TEST_CASE("Third example from leetcode")
{
    vector<int> nums1 = {};
    vector<int> nums2 = { 1 };
    REQUIRE_THAT(merge(nums1, nums2), Equals<int>({ 1 }));
}

TEST_CASE("First own example")
{
    vector<int> nums1 = { 1, 4, 7, 8, 10, 11 };
    vector<int> nums2 = { 1, 8, 10 };
    REQUIRE_THAT(merge(nums1, nums2), Equals<int>({ 1, 1, 4, 7, 8, 8, 10, 10, 11 }));
    REQUIRE_THAT(merge(nums2, nums1), Equals<int>({ 1, 1, 4, 7, 8, 8, 10, 10, 11 }));
}

TEST_CASE("Second own example")
{
    vector<int> nums1 = { 3, 5, 9, 17, 29, 30, 31 };
    vector<int> nums2 = { 1, 4, 7, 8, 10, 11 };
    REQUIRE_THAT(merge(nums1, nums2), Equals<int>({ 1, 3, 4, 5, 7, 8, 9, 10, 11, 17, 29, 30, 31 }));
    REQUIRE_THAT(merge(nums2, nums1), Equals<int>({ 1, 3, 4, 5, 7, 8, 9, 10, 11, 17, 29, 30, 31 }));
}
