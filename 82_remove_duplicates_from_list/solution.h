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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* preLeft = nullptr;
        ListNode* left = head;
        ListNode* right = left;

        while (right)
        {
            ListNode* next = right->next;
            if (next && next->val == left->val)
            {
                right = next;
                continue;
            }
            if (right != left)
            {
                // Forget nodes from list.
                if (preLeft)
                {
                    preLeft->next = next;
                }
                else
                {
                    head = next;
                }
            }
            else
            {
                preLeft = right;
            }
            left = next;
            right = next;
        }

        return head;
    }
};
