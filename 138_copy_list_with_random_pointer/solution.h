#include <unordered_map>

using namespace std;

struct Node
{
    int val = 0;
    Node* next = nullptr;
    Node* random = nullptr;

    explicit Node(int x)
        : val(x)
        , next(nullptr)
        , random(nullptr)
    {
    }

    ~Node()
    {
        delete next;
        next = nullptr;
    }
};

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if (!head)
        {
            return nullptr;
        }

        unordered_map<Node*, Node*> nodeToNewNode;

        Node* newHead = new Node(head->val);
        nodeToNewNode[head] = newHead;

        Node* prev = newHead;
        for (Node* node = head->next; node != nullptr; node = node->next)
        {
            prev->next = new Node(node->val);
            nodeToNewNode[node] = prev->next;
            prev = prev->next;
        }

        for (Node *node = head, *newNode = newHead; node != nullptr; node = node->next, newNode = newNode->next)
        {
            if (node->random != nullptr)
            {
                newNode->random = nodeToNewNode[node->random];
            }
        }

        return newHead;
    }
};
