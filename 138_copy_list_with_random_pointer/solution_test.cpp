#include "solution.h"

#include <memory>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;

namespace
{
unique_ptr<Node> createList(std::vector<int> ints, std::vector<size_t> randomPointers)
{
    if (ints.empty())
    {
        return nullptr;
    }
    if (ints.size() != randomPointers.size())
    {
        throw invalid_argument("initializers mismatch");
    }

    unique_ptr<Node> head(new Node(ints[0]));
    Node* prev = head.get();
    vector<Node*> nodes = { head.get() };
    for (size_t i = 1, size = ints.size(); i < size; ++i)
    {
        prev->next = new Node(ints[i]);
        nodes.push_back(prev->next);
        prev = prev->next;
    }

    for (size_t i = 0, size = randomPointers.size(); i < size; ++i)
    {
        if (size_t toIndex = randomPointers[i]; toIndex < size)
        {
            nodes[i]->random = nodes[toIndex];
        }
    }

    return head;
}

bool hasCycle(Node* head)
{
    const Node* slow = head;
    const Node* fast = head;
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

vector<int> listToVector(Node* head)
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

unique_ptr<Node> copyRandomList(Node* node)
{
    Solution sol;
    return unique_ptr<Node>(sol.copyRandomList(node));
}

vector<size_t> toRandomPointers(Node* head)
{
    vector<Node*> nodes;
    for (Node *node = head; node != nullptr; node = node->next)
    {
        nodes.push_back(node);
    }

    vector<size_t> results;
    for (Node *node = head; node != nullptr; node = node->next)
    {
        if (node->random == nullptr)
        {
            results.push_back(size_t(-1));
        }
        else
        {
            auto it = std::ranges::find(nodes, node->random);
            if (it == nodes.end())
            {
                throw invalid_argument("invliad random pointer in list");
            }
            results.push_back(distance(nodes.begin(), it));
        }
    }
    return results;
}
} // namespace

TEST_CASE("Own examples")
{
    {
        const vector<size_t> randomPointers{ size_t(-1), 1, 3, 2, 2 };
        const vector<int> values{ 12, 14, 16, 18, 20 };
        auto list = createList(values, randomPointers);
        auto copy = copyRandomList(list.get());
        REQUIRE_THAT(listToVector(list.get()), Equals(values));
        REQUIRE_THAT(toRandomPointers(list.get()), Equals(randomPointers));
    }
    {
        const vector<size_t> randomPointers{ 4, 3, 2, 1, 0 };
        const vector<int> values{ 12, 14, 16, 18, 20 };
        auto list = createList(values, randomPointers);
        auto copy = copyRandomList(list.get());
        REQUIRE_THAT(listToVector(list.get()), Equals(values));
        REQUIRE_THAT(toRandomPointers(list.get()), Equals(randomPointers));
    }
    {
        auto list = createList({}, {});
        auto copy = copyRandomList(list.get());
        REQUIRE_THAT(listToVector(list.get()), Equals<int>({}));
        REQUIRE_THAT(toRandomPointers(list.get()), Equals<size_t>({}));
    }
}
