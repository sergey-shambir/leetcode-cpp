#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string prefix = strs[0];
        for (size_t i = 1, size = strs.size(); i < size; ++i)
        {
            size_t length = longestCommonPrefix(prefix, strs[i]);
            prefix = prefix.substr(0, length);
        }
        return prefix;
    }

private:
    size_t longestCommonPrefix(const string& a, const string& b)
    {
        const size_t size = (std::min)(a.length(), b.length());
        for (size_t i = 0; i < size; ++i)
        {
            if (a[i] != b[i])
            {
                return i;
            }
        }
        return size;
    }
};
