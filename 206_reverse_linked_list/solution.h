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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* node = head;
        while (node)
        {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }

        return prev;
    }
};
