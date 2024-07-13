#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::UnorderedEquals;

vector<vector<string>> groupAnagrams(vector<string> strs)
{
    Solution s;
    auto results = s.groupAnagrams(strs);
    for (auto& result : results)
    {
        std::ranges::sort(result);
    }
    return results;
}

TEST_CASE("Leetcode examples")
{
    // Input: strs = ["eat","tea","tan","ate","nat","bat"]
    // Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    REQUIRE_THAT(
        groupAnagrams({ "eat", "tea", "tan", "ate", "nat", "bat" }),
        UnorderedEquals<vector<string>>({ { "bat" }, { "nat", "tan" }, { "ate", "eat", "tea" } }));

    // Input: strs = [""]
    // Output: [[""]]
    REQUIRE_THAT(
        groupAnagrams({ "" }),
        UnorderedEquals<vector<string>>({ { "" } }));

    // Input: strs = ["a"]
    // Output: [["a"]]
    REQUIRE_THAT(
        groupAnagrams({ "a" }),
        UnorderedEquals<vector<string>>({ { "a" } }));
}
