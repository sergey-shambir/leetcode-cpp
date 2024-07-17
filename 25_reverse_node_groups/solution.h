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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head || k <= 1)
        {
            return head;
        }

        ListNode* newHead = reverseOneGroup(head, k);
        if (!newHead)
        {
            return head;
        }

        ListNode* preTail = head;
        while (ListNode* tail = preTail->next)
        {
            if (ListNode* newTail = reverseOneGroup(tail, k))
            {
                preTail->next = newTail;
                preTail = tail;
            }
            else
            {
                break;
            }
        }
        return newHead;
    }

private:
    // Returns nullptr when there are less than k nodes in least
    ListNode* reverseOneGroup(ListNode* head, int k)
    {
        ListNode* prev = head;
        ListNode* node = prev->next;
        for (int i = 1; i < k; ++i)
        {
            if (node == nullptr)
            {
                // Revert changes
                head->next = nullptr;
                reverseOneGroup(prev, i);
                return nullptr;
            }
            else
            {
                ListNode* next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }
        }
        head->next = node;

        return prev;
    }
};
