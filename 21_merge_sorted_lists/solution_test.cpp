#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;

namespace
{
class ListNodeFixture
{
public:
    std::pair<ListNode*, ListNode*> createTwoLists(std::initializer_list<int> first, std::initializer_list<int> second)
    {
        nodes.clear();
        nodes.reserve(first.size() + second.size());

        return make_pair(createList(first), createList(second));
    }

private:
    ListNode* createList(std::initializer_list<int> ints)
    {
        if (ints.size() == 0)
        {
            return nullptr;
        }

        const size_t startIndex = nodes.size();
        for (auto it = ints.begin(), end = ints.end(); it < end; ++it)
        {
            nodes.emplace_back(*it);
        }
        size_t lastIndex = nodes.size() - 1;
        for (size_t i = startIndex; i < lastIndex; ++i)
        {
            nodes[i].next = &nodes[i + 1];
        }

        return &nodes[startIndex];
    }

    vector<ListNode> nodes;
};

vector<int> listToVector(ListNode* head)
{
    vector<int> result;
    for (; head != nullptr; head = head->next)
    {
        result.push_back(head->val);
    }
    return result;
}
} // namespace

TEST_CASE("Own examples")
{
    Solution sol;
    ListNodeFixture fixture;
    {
        auto [list1, list2] = fixture.createTwoLists({ 1, 2, 10, 19 }, { -20, -14 });
        auto mergedList = sol.mergeTwoLists(list1, list2);
        REQUIRE_THAT(listToVector(mergedList), Equals<int>({ -20, -14, 1, 2, 10, 19 }));
    }
    {
        auto [list1, list2] = fixture.createTwoLists({ 1, 2, 10, 19 }, { 14, 20, 24 });
        auto mergedList = sol.mergeTwoLists(list1, list2);
        REQUIRE_THAT(listToVector(mergedList), Equals<int>({ 1, 2, 10, 14, 19, 20, 24 }));
    }
    {
        auto [list1, list2] = fixture.createTwoLists({ 1, 3, 5, 9, 11 }, { 2, 4, 6, 8 });
        auto mergedList = sol.mergeTwoLists(list1, list2);
        REQUIRE_THAT(listToVector(mergedList), Equals<int>({ 1, 2, 3, 4, 5, 6, 8, 9, 11 }));
    }
}
