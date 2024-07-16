#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <stdexcept>

using Catch::Matchers::Equals;

namespace
{
class ListNodeFixture
{
public:
    ListNode* createList(std::initializer_list<int> ints)
    {
        nodes.clear();
        nodes.reserve(ints.size());
        return createListImpl(ints);
    }

private:
    ListNode* createListImpl(std::initializer_list<int> ints)
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

bool hasCycle(ListNode* head)
{
    const ListNode* slow = head;
    const ListNode* fast = head;
    while (slow != nullptr && fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

vector<int> listToVector(ListNode* head)
{
    if (hasCycle(head))
    {
        throw invalid_argument("list contains cycle");
    }

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
        auto ints = fixture.createList({ 57 });
        sol.reverseBetween(ints, 1, 1);
        REQUIRE_THAT(listToVector(ints), Equals<int>({ 57 }));
    }
    {
        auto ints = fixture.createList({ 57, 28, 19 });
        sol.reverseBetween(ints, 1, 1);
        REQUIRE_THAT(listToVector(ints), Equals<int>({ 57, 28, 19 }));
    }
    {
        auto ints = fixture.createList({ 1, 2, 3, 4, 5 });
        sol.reverseBetween(ints, 2, 4);
        REQUIRE_THAT(listToVector(ints), Equals<int>({ 1, 4, 3, 2, 5 }));
    }
}
