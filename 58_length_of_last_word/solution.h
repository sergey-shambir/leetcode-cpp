#pragma once

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        const size_t size = s.size();

        size_t wordStart = 0;
        size_t wordEnd = size - 1;
        size_t i = size - 1;
        for (; i < size; --i)
        {
            if (s[i] != ' ')
            {
                wordEnd = i;
                break;
            }
        }
        for (; i < size; --i)
        {
            if (s[i] == ' ')
            {
                wordStart = i+1;
                break;
            }
        }
        return wordEnd - wordStart + 1;
    }
};
