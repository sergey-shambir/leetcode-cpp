#include <memory>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
    int val = 0;
    ListNode* next = nullptr;

    explicit ListNode(int val = 0, ListNode* next = nullptr)
        : val(val)
        , next(next)
    {
    }
};

class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* start = head;
        ListNode* beforeStart = nullptr;
        const int reversedCount = right - left + 1;
        while (--left)
        {
            beforeStart = start;
            start = start->next;
        }

        ListNode* tail = reverseListWithLimit(start, reversedCount);
        if (beforeStart)
        {
            beforeStart->next = tail;
        }
        else
        {
            head = tail;
        }

        return head;
    }

private:
    ListNode* reverseListWithLimit(ListNode* head, int limit)
    {
        ListNode* prev = nullptr;
        ListNode* node = head;
        ListNode* next = nullptr;
        while (limit--)
        {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }

        head->next = next;

        return prev;
    }
};
