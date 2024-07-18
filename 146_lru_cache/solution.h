#pragma once

#include <stdexcept>
#include <unordered_map>

using namespace std;

class DoubleLinkedList
{
public:
    struct Node
    {
        int key = 0;
        int value = 0;
        Node* prev = nullptr;
        Node* next = nullptr;

        explicit Node(int key, int value, Node* prev = nullptr, Node* next = nullptr)
            : key(key)
            , value(value)
            , prev(prev)
            , next(next)
        {
        }

        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
    };

    ~DoubleLinkedList()
    {
        Node* node = head;
        while (node != nullptr)
        {
            Node* next = node->next;
            delete node;
            node = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    DoubleLinkedList() = default;
    DoubleLinkedList(const DoubleLinkedList&) = delete;
    DoubleLinkedList& operator=(const DoubleLinkedList&) = delete;

    Node* pushBack(Node* node)
    {
        node->next = nullptr;
        node->prev = tail;
        if (tail)
        {
            tail->next = node;
        }
        else
        {
            head = node;
        }
        tail = node;
        return node;
    }

    void moveBack(Node* node)
    {
        if (node == tail)
        {
            return;
        }
        Node* prev = node->prev;
        if (prev)
        {
            prev->next = node->next;
        }
        else
        {
            head = node->next;
        }
        if (node->next)
        {
            node->next->prev = prev;
        }
        tail->next = node;
        node->next = nullptr;
        node->prev = tail;
        tail = node;
    }

    Node* front() const
    {
        return head;
    }

    Node* back() const
    {
        return tail;
    }

    Node* popFront()
    {
        if (head)
        {
            Node* oldHead = head;
            head = head->next;
            oldHead->next = nullptr;
            if (head)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            return oldHead;
        }
        return nullptr;
    }

    DoubleLinkedList(DoubleLinkedList&& other)
    {
        swap(head, other.head);
        swap(tail, other.tail);
    }

    DoubleLinkedList& operator=(DoubleLinkedList&& other)
    {
        swap(head, other.head);
        swap(tail, other.tail);
        return *this;
    }

private:
    Node* head = nullptr;
    Node* tail = nullptr;
};

class LRUCache
{
public:
    LRUCache(int capacity)
        : capacity(capacity)
    {
    }

    int get(int key)
    {
        if (auto it = keyToNodeMap.find(key); it != keyToNodeMap.end())
        {
            auto* node = it->second;
            values.moveBack(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (auto it = keyToNodeMap.find(key); it != keyToNodeMap.end())
        {
            auto* node = it->second;
            node->value = value;
            values.moveBack(node);
        }
        else if (keyToNodeMap.size() >= capacity)
        {
            auto* node = values.popFront();
            keyToNodeMap.erase(node->key);

            node->key = key;
            node->value = value;
            values.pushBack(node);
            keyToNodeMap[key] = node;
        }
        else
        {
            auto* node = new DoubleLinkedList::Node(key, value);
            values.pushBack(node);
            keyToNodeMap[key] = node;
        }
    }

private:
    int capacity = 0;
    unordered_map<int, DoubleLinkedList::Node*> keyToNodeMap;
    DoubleLinkedList values;
};
