#pragma once

#include <memory>

using namespace std;

struct ListNode
{
    int val = 0;
    ListNode* next = nullptr;

    explicit ListNode(int x = 0, ListNode* next = nullptr)
        : val(x)
        , next(nullptr)
    {
    }

    ~ListNode()
    {
        delete next;
        next = nullptr;
    }

    ListNode(ListNode&&) = delete;
    ListNode(const ListNode&) = delete;
    ListNode& operator=(ListNode&&) = delete;
    ListNode& operator=(const ListNode&) = delete;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        unique_ptr<ListNode> head;
        ListNode* node = nullptr;
        while (l1 || l2 || carry)
        {
            int digit1 = 0;
            int digit2 = 0;
            if (l1)
            {
                digit1 = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                digit2 = l2->val;
                l2 = l2->next;
            }
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* next = new ListNode(sum);
            if (!head)
            {
                head.reset(next);
            }
            else
            {
                node->next = next;
            }
            node = next;
        }

        return head.release();
    }
};
