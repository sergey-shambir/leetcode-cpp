#pragma once

#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mapping{
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };

        stack<char> unclosed;
        for (char ch : s)
        {
            if (mapping.contains(ch))
            {
                unclosed.push(ch);
            }
            else
            {
                if (unclosed.empty() || mapping[unclosed.top()] != ch)
                {
                    return false;
                }
                unclosed.pop();
            }
        }

        return unclosed.empty();
    }
};
