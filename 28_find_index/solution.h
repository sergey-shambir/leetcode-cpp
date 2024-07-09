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

        const char* maxHaystackPtr = haystack.data() + (haystack.size() - needle.size());

        for (const char* haystackPtr = haystack.data(); haystackPtr <= maxHaystackPtr; ++haystackPtr)
        {
            if (startsWith(haystackPtr, needle.data(), needle.size()))
            {
                return int(haystackPtr - haystack.data());
            }
        }
        return -1;
    }

private:
    bool startsWith(const char* str, const char* prefix, size_t prefixSize) const
    {
        const char* end = str + prefixSize;
        for (; str < end; ++str, ++prefix)
        {
            if (*str != *prefix)
            {
                return false;
            }
        }
        return true;
    }
};
