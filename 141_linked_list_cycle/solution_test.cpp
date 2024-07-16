#include "solution.h"

#include <catch2/catch_test_macros.hpp>

namespace
{
class ListNodeFixture
{
public:
    ListNode* createList(std::initializer_list<int> ints, size_t loopStartIndex = size_t(-1))
    {
        if (ints.size() == 0)
        {
            return nullptr;
        }

        nodes.clear();
        nodes.reserve(ints.size());

        for (auto it = ints.begin(), end = ints.end(); it < end; ++it)
        {
            nodes.emplace_back(*it);
        }

        size_t lastIndex = nodes.size() - 1;
        for (size_t i = 0; i < lastIndex; ++i)
        {
            nodes[i].next = &nodes[i + 1];
        }
        if (loopStartIndex <= lastIndex)
        {
            nodes[lastIndex].next = &nodes[loopStartIndex];
        }

        return &nodes[0];
    }

private:
    vector<ListNode> nodes;
};
} // namespace

TEST_CASE("Own examples")
{
    Solution sol;
    ListNodeFixture fixture;

    REQUIRE(sol.hasCycle(fixture.createList({ 100, -200, 831, 182, 291 }, 2)));
    REQUIRE(sol.hasCycle(fixture.createList({ 100, -200, 831, 182, 291 }, 1)));

    REQUIRE(!sol.hasCycle(fixture.createList({ 100, -200, 831, 182, 291 })));
    REQUIRE(!sol.hasCycle(fixture.createList({ 100 })));
    REQUIRE(!sol.hasCycle(fixture.createList({})));
}
