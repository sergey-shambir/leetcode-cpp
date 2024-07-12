#include "solution.h"

#include <catch2/catch_test_macros.hpp>

namespace
{
bool wordPattern(string p, string s)
{
    Solution solution;
    return solution.wordPattern(p, s);
}
} // namespace

TEST_CASE("Own examples")
{
    REQUIRE(wordPattern("gbrrgrg", "green blue red red green red green"));
    REQUIRE(wordPattern("abccaca", "green blue red red green red green"));
    REQUIRE(wordPattern("a", "a"));

    REQUIRE(!wordPattern("abccac", "green blue red red green red green"));
    REQUIRE(!wordPattern("abccacaa", "green blue red red green red green"));
    REQUIRE(!wordPattern("a", "a b"));
}

TEST_CASE("Leetcode examples")
{
    // Input: pattern = "abba", s = "dog cat cat dog"
    // Output: true
    REQUIRE(wordPattern("abba", "dog cat cat dog"));

    // Input: pattern = "abba", s = "dog cat cat fish"
    // Output: false
    REQUIRE(!wordPattern("abba", "dog cat cat fish"));

    // Input: pattern = "aaaa", s = "dog cat cat dog"
    // Output: false
    REQUIRE(!wordPattern("aaaa", "dog cat cat dog"));
}
