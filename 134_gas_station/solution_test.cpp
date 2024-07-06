#include "solution.h"

#include <catch2/catch_test_macros.hpp>

int canCompleteCircuit(std::vector<int> gas, std::vector<int> costs)
{
    if (gas.size() != costs.size())
    {
        throw std::logic_error("inputs size mismatch");
    }

    Solution s;
    return s.canCompleteCircuit(gas, costs);
}

TEST_CASE("Should start from 3rd station")
{
    Solution s;
    REQUIRE(3 == canCompleteCircuit({ 1, 2, 3, 4, 5 }, { 3, 4, 5, 1, 2 }));
}

TEST_CASE("No solution exists #1")
{
    Solution s;
    REQUIRE(-1 == canCompleteCircuit({ 2, 3, 4 }, { 3, 4, 3 }));
}

TEST_CASE("Should start on 5th station")
{
    Solution s;
    REQUIRE(5 == canCompleteCircuit({ 9, 11, 8, 12, 7, 13, 10 }, { 10, 10, 10, 10, 10, 10, 10 }));
}

TEST_CASE("No solution exists #2")
{
    Solution s;
    REQUIRE(-1 == canCompleteCircuit({ 9, 11, 8, 12, 7, 13, 10 }, { 10, 10, 10, 10, 10, 10, 11 }));
}

TEST_CASE("Should start on 4th station")
{
    Solution s;
    REQUIRE(4 == canCompleteCircuit({ 5, 1, 2, 3, 4 }, { 4, 4, 1, 5, 1 }));
}
