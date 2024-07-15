#pragma once

#include <stack>
#include <unordered_map>

using namespace std;

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        int newMin = values.empty() ? val : ((min)(val, getMin()));

        values.push(val);
        try
        {
            minMap[values.size() - 1] = newMin;
        }
        catch (...)
        {
            values.pop();
            throw;
        }
    }

    void pop()
    {
        minMap.erase(values.size() - 1);
        values.pop();
    }

    int top()
    {
        return values.top();
    }

    int getMin()
    {
        return minMap[values.size() - 1];
    }

private:
    stack<int> values;
    unordered_map<size_t, int> minMap;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
