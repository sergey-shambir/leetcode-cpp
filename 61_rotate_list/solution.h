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
    ListNode* rotateRight(ListNode* head, int k)
    {
        const auto [size, tail] = getSizeAndTail(head);
        if (size <= 1)
        {
            return head;
        }

        const int newHeadIndex = size - (k % size);
        if (newHeadIndex == size)
        {
            return head;
        }

        ListNode* newTail = nullptr;
        ListNode* newHead = head;
        for (int i = 0; i < newHeadIndex; ++i)
        {
            newTail = newHead;
            newHead = newHead->next;
        }
        tail->next = head;
        newTail->next = nullptr;

        return newHead;
    }

private:
    static pair<int, ListNode*> getSizeAndTail(ListNode* head)
    {
        int size = 0;
        ListNode* tail = nullptr;
        while (head)
        {
            ++size;
            tail = head;
            head = head->next;
        }
        return { size, tail };
    }
};
