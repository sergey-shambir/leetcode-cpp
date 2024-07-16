#include <memory>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
    int val = 0;
    ListNode* next = nullptr;

    explicit ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
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
};
