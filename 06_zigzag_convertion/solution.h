#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        const size_t period = 2 * size_t(numRows) - 2;
        const size_t lastRowIndex = size_t(numRows) - 1;
        const size_t size = s.size();
        string result;

        const auto copyCharSafe = [&](size_t index) {
            if (index < size)
            {
                result.push_back(s[index]);
            }
        };

        // Slice first row
        for (size_t i = 0; i < size; i += period)
        {
            result.push_back(s[i]);
        }
        for (size_t rowIndex = 1; rowIndex < lastRowIndex; ++rowIndex)
        {
            for (size_t i = 0; i < size; i += period)
            {
                copyCharSafe(i + rowIndex);
                copyCharSafe(i + period - rowIndex);
            }
        }
        // Slice last row
        for (size_t i = lastRowIndex; i < size; i += period)
        {
            result.push_back(s[i]);
        }

        return result;
    }
};
