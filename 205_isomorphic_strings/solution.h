#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, char> charMapping;
        unordered_set<char> usedChars;

        const char* sp = s.data();
        const char* tp = t.data();
        for (const char* sEnd = s.data() + s.length(); sp < sEnd; sp++, tp++)
        {
            if (const auto it = charMapping.find(*sp); it != charMapping.end())
            {
                if (it->second != *tp)
                {
                    return false;
                }
            }
            else
            {
                if (usedChars.contains(*tp))
                {
                    return false;
                }
                charMapping.emplace(*sp, *tp);
                usedChars.emplace(*tp);
            }
        }
        return true;
    }
};
