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

vector<int> removeNthFromEnd(const vector<int>& ints, int n)
{
    ListNodeFixture fixture;
    auto list = fixture.createList(ints);

    Solution sol;
    list = sol.removeNthFromEnd(list, n);

    return listToVector(list);
}
} // namespace

TEST_CASE("Own examples")
{
    REQUIRE_THAT(removeNthFromEnd({ 1, 2, 3, 4, 5, 6 }, 1), Equals<int>({ 1, 2, 3, 4, 5 }));
    REQUIRE_THAT(removeNthFromEnd({ 1, 2, 3, 4, 5, 6 }, 2), Equals<int>({ 1, 2, 3, 4, 6 }));
    REQUIRE_THAT(removeNthFromEnd({ 1, 2, 3, 4, 5, 6 }, 3), Equals<int>({ 1, 2, 3, 5, 6 }));
    REQUIRE_THAT(removeNthFromEnd({ 1, 2, 3, 4, 5, 6 }, 4), Equals<int>({ 1, 2, 4, 5, 6 }));
    REQUIRE_THAT(removeNthFromEnd({ 1, 2, 3, 4, 5, 6 }, 5), Equals<int>({ 1, 3, 4, 5, 6 }));
    REQUIRE_THAT(removeNthFromEnd({ 1, 2, 3, 4, 5, 6 }, 6), Equals<int>({ 2, 3, 4, 5, 6 }));

    REQUIRE_THAT(removeNthFromEnd({ 1, 2, 3, 4, 5, 6 }, 0), Equals<int>({ 1, 2, 3, 4, 5, 6 }));
    REQUIRE_THAT(removeNthFromEnd({ 1, 2, 3, 4, 5, 6 }, 7), Equals<int>({ 1, 2, 3, 4, 5, 6 }));
}
