#include "solution.h"

#include <catch2/catch_test_macros.hpp>

namespace
{
} // namespace

TEST_CASE("Own examples")
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    REQUIRE(cache.get(1) == 1);
    cache.put(3, 3);
    REQUIRE(cache.get(2) == -1);
    cache.put(4, 4);
    REQUIRE(cache.get(1) == -1);
    REQUIRE(cache.get(3) == 3);
    REQUIRE(cache.get(4) == 4);
}
