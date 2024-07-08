#include "solution.h"
#include <iostream>

#include <catch2/catch_test_macros.hpp>

bool isInRange(int value, int from, int to)
{
    return value >= from && value <= to
;}

TEST_CASE("First example from leetcode")
{
    RandomizedSet randomizedSet;
    REQUIRE(randomizedSet.insert(1) == true);
    REQUIRE(randomizedSet.remove(2) == false);
    REQUIRE(randomizedSet.insert(2) == true);

    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 2));
    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 2));
    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 2));

    REQUIRE(randomizedSet.remove(1) == true);
    REQUIRE(randomizedSet.insert(2) == false);

    REQUIRE(randomizedSet.getRandom() == 2);
    REQUIRE(randomizedSet.getRandom() == 2);
    REQUIRE(randomizedSet.getRandom() == 2);
}

TEST_CASE("Own examples")
{
    RandomizedSet randomizedSet;
    REQUIRE(randomizedSet.insert(1) == true);
    REQUIRE(randomizedSet.insert(2) == true);
    REQUIRE(randomizedSet.insert(3) == true);
    REQUIRE(randomizedSet.insert(4) == true);
    REQUIRE(randomizedSet.insert(5) == true);
    REQUIRE(randomizedSet.insert(5) == false);
    REQUIRE(randomizedSet.insert(6) == true);
    REQUIRE(randomizedSet.insert(7) == true);
    REQUIRE(randomizedSet.insert(8) == true);
    REQUIRE(randomizedSet.insert(9) == true);
    REQUIRE(randomizedSet.insert(10) == true);
    REQUIRE(randomizedSet.insert(10) == false);
    REQUIRE(randomizedSet.insert(11) == true);

    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 11));
    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 11));
    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 11));

    REQUIRE(randomizedSet.remove(8) == true);
    REQUIRE(randomizedSet.remove(9) == true);
    REQUIRE(randomizedSet.remove(10) == true);
    REQUIRE(randomizedSet.remove(10) == false);
    REQUIRE(randomizedSet.remove(11) == true);

    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 7));
    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 7));
    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 7));

    REQUIRE(randomizedSet.remove(7) == true);
    REQUIRE(randomizedSet.remove(6) == true);
    REQUIRE(randomizedSet.remove(5) == true);
    REQUIRE(randomizedSet.remove(4) == true);
    REQUIRE(randomizedSet.remove(3) == true);

    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 2));
    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 2));
    REQUIRE(isInRange(randomizedSet.getRandom(), 1, 2));
}
