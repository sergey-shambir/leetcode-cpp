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
    ListNode* partition(ListNode* head, int x)
    {
        pair<ListNode*, ListNode*> less{ nullptr, nullptr };
        pair<ListNode*, ListNode*> notLess{ nullptr, nullptr };
        while (head)
        {
            ListNode* next = head->next;
            if (head->val < x)
            {
                Push(less, head);
            }
            else
            {
                Push(notLess, head);
            }
            head = next;
        }
        return Concat(less, notLess);
    }

private:
    ListNode* Concat(pair<ListNode*, ListNode*> headList, pair<ListNode*, ListNode*> tailList)
    {
        if (headList.second == nullptr)
        {
            return tailList.first;
        }
        headList.second->next = tailList.first;

        return headList.first;
    }

    void Push(pair<ListNode*, ListNode*>& list, ListNode* node)
    {
        if (list.second == nullptr)
        {
            list.first = node;
            list.second = node;
        }
        else
        {
            list.second->next = node;
            list.second = node;
        }
        node->next = nullptr;
    }
};
