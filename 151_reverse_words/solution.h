#pragma once

#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        const size_t size = s.length();
        string result;

        size_t i = size - 1;
        while (i < size)
        {
            size_t wordStart = 0;
            size_t wordEnd = size;
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
                    wordStart = i + 1;
                    break;
                }
            }
            if (wordEnd < size)
            {
                if (!result.empty())
                {
                    result.append(" ");
                }
                result.append(s.substr(wordStart, wordEnd - wordStart + 1));
            }
        }

        return result;
    }
};
