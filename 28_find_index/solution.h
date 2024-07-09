#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() > haystack.size())
        {
            return -1;
        }

        const size_t maxI = haystack.size() - needle.size();

        for (size_t i = 0; i <= maxI; ++i)
        {
            bool matches = true;
            for (size_t j = 0, endJ = needle.size(); j < endJ; ++j)
            {
                if (haystack[i + j] != needle[j])
                {
                    matches = false;
                    break;
                }
            }
            if (matches)
            {
                return int(i);
            }
        }
        return -1;
    }
};
