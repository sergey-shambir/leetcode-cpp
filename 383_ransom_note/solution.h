#pragma once

#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, unsigned> letters;
        for (const char ch : magazine)
        {
            letters[ch] += 1;
        }

        for (const char ch : ransomNote)
        {
            const unsigned countLeft = letters[ch]--;
            if (countLeft < 1)
            {
                return false;
            }
        }
        return true;
    }
};
