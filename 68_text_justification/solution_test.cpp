#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;

vector<string> fullJustify(vector<string> words, int maxWidth)
{
    Solution s;
    return s.fullJustify(words, maxWidth);
}

// Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
TEST_CASE("1st example from leetcode")
{
    REQUIRE_THAT(
        fullJustify({ "This", "is", "an", "example", "of", "text", "justification." }, 16),
        Equals<string>({ "This    is    an", "example  of text", "justification.  " }));
}

// Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
TEST_CASE("2nd example from leetcode")
{
    REQUIRE_THAT(
        fullJustify({ "What", "must", "be", "acknowledgment", "shall", "be" }, 16),
        Equals<string>({ "What   must   be", "acknowledgment  ", "shall be        " }));
}

// Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]
TEST_CASE("3rd example from leetcode")
{
    REQUIRE_THAT(
        fullJustify({ "Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do" }, 20),
        Equals<string>({

            "Science  is  what we",
            "understand      well",
            "enough to explain to",
            "a  computer.  Art is",
            "everything  else  we",
            "do                  " }));
}

TEST_CASE("Edge cases")
{
    REQUIRE_THAT(
        fullJustify({ "This"}, 4),
        Equals<string>({ "This" }));
    REQUIRE_THAT(
        fullJustify({ "This"}, 8),
        Equals<string>({ "This    " }));
    REQUIRE_THAT(
        fullJustify({ "Text", "with", "loooooooong", "string"}, 14),
        Equals<string>({ "Text      with", "loooooooong   ", "string        " }));
}
