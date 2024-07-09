#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        /*
            Symbol       Value
            I             1
            V             5
            X             10
            L             50
            C             100
            D             500
            M             1000
        */
        string digits{ "IVXLCDM" };
        vector<int> values{ 1, 5, 10, 50, 100, 500, 1000 };

        int result = 0;

        const size_t size = s.length();
        size_t i = 0;
        for (; i < size - 1; ++i)
        {
            size_t pos = digits.find(s[i]);
            int value = values[pos];

            size_t nextPos = digits.find(s[i + 1]);
            int nextValue = values[nextPos];

            if (nextValue > value)
            {
                result += (nextValue - value);
                ++i;
            }
            else
            {
                result += value;
            }
        }
        if (i < size)
        {
            size_t pos = digits.find(s[i]);
            result += values[pos];
        }

        return result;
    }
};
