#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Own tests")
{
    Solution s;
    REQUIRE(s.lengthOfLastWord("Own tests") == 5);
    REQUIRE(s.lengthOfLastWord(" Own tests ") == 5);
    REQUIRE(s.lengthOfLastWord("Own tests  ") == 5);
    REQUIRE(s.lengthOfLastWord("Owntests") == 8);
    REQUIRE(s.lengthOfLastWord("s") == 1);
}
