#pragma once

#include <string>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        const char* ps = s.data();
        const char* pt = t.data();
        const char* sEnd = s.data() + s.size();
        const char* tEnd = t.data() + t.size();

        while (ps < sEnd && pt < tEnd)
        {
            if (*ps == *pt)
            {
                ++ps;
                ++pt;
            }
            else
            {
                ++pt;
            }
        }
        return (ps == sEnd);
    }
};
