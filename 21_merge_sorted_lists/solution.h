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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (list1 != nullptr || list2 != nullptr)
        {
            ListNode* next = nullptr;
            if (list1 && list2)
            {
                if (list1->val < list2->val)
                {
                    next = list1;
                    list1 = list1->next;
                }
                else
                {
                    next = list2;
                    list2 = list2->next;
                }
            }
            else if (list1)
            {
                next = list1;
                list1 = list1->next;
            }
            else
            {
                next = list2;
                list2 = list2->next;
            }
            if (!tail)
            {
                head = tail = next;
            }
            else
            {
                tail->next = next;
                tail = next;
            }
        }
        return head;
    }
};
