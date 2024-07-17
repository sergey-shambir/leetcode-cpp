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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int size = 0;
        for (auto* node = head; node; node = node->next)
        {
            ++size;
        }
        if (n <= 0 || n > size)
        {
            return head;
        }

        ListNode* node = head;
        ListNode* prev = nullptr;
        for (int index = size - n; index; --index)
        {
            prev = node;
            node = node->next;
        }

        // Should be deleted?
        // delete node;

        if (!prev)
        {
            return node->next;
        }
        prev->next = node->next;
        return head;
    }
};
