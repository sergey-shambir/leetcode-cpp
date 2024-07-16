#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <stdint.h>

namespace
{
std::unique_ptr<ListNode> createListFromNumber(uint64_t value)
{
    auto head = make_unique<ListNode>(static_cast<int>(value % 10));
    ListNode* node = head.get();
    for (value = value / 10; value > 0; value = value / 10)
    {
        node->next = new ListNode(static_cast<int>(value % 10));
        node = node->next;
    }

    return head;
}

uint64_t readNumberFromList(ListNode* head)
{
    uint64_t result = 0;
    uint64_t factor = 1;
    for (; head; head = head->next)
    {
        result += static_cast<uint64_t>(head->val) * factor;
        factor *= 10;
    }
    return result;
}

uint64_t addTwoNumbers(uint64_t num1, uint64_t num2)
{
    auto l1 = createListFromNumber(num1);
    auto l2 = createListFromNumber(num2);
    Solution sol;
    unique_ptr<ListNode> result(sol.addTwoNumbers(l1.get(), l2.get()));
    return readNumberFromList(result.get());
}
} // namespace

TEST_CASE("Own examples")
{
    Solution s;
    REQUIRE(addTwoNumbers(0, 0) == 0);
    REQUIRE(addTwoNumbers(0, 7) == 7);
    REQUIRE(addTwoNumbers(7, 0) == 7);
    REQUIRE(addTwoNumbers(4, 5) == 9);
    REQUIRE(addTwoNumbers(8, 7) == 15);

    REQUIRE(addTwoNumbers(0, 56) == 56);
    REQUIRE(addTwoNumbers(56, 0) == 56);
    REQUIRE(addTwoNumbers(156, 111) == 267);
    REQUIRE(addTwoNumbers(999, 999) == 1998);
}
