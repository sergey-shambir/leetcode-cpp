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
    ListNode* createList(const std::vector<int>& ints)
    {
        nodes.clear();
        nodes.reserve(ints.size());
        return createListImpl(ints);
    }

private:
    ListNode* createListImpl(const std::vector<int>& ints)
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

vector<int> reverseKGroup(const vector<int>& ints, int k)
{
    ListNodeFixture fixture;
    auto list = fixture.createList(ints);

    Solution sol;
    list = sol.reverseKGroup(list, k);

    return listToVector(list);
}
} // namespace

TEST_CASE("Own examples")
{
    REQUIRE_THAT(reverseKGroup({ 1, 2, 3, 4, 5, 6 }, 2), Equals<int>({ 2, 1, 4, 3, 6, 5 }));
    REQUIRE_THAT(reverseKGroup({ 1, 2, 3, 4, 5, 6 }, 3), Equals<int>({ 3, 2, 1, 6, 5, 4 }));
    REQUIRE_THAT(reverseKGroup({ 1, 2, 3, 4, 5, 6, 7 }, 2), Equals<int>({ 2, 1, 4, 3, 6, 5, 7 }));
    REQUIRE_THAT(reverseKGroup({ 1, 2, 3, 4, 5, 6, 7 }, 3), Equals<int>({ 3, 2, 1, 6, 5, 4, 7 }));
    REQUIRE_THAT(reverseKGroup({ 1, 2, 3, 4, 5, 6, 7, 8 }, 3), Equals<int>({ 3, 2, 1, 6, 5, 4, 7, 8 }));
}
