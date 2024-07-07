#pragma once

#include <array>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        array<pair<int, int>, 4> window;
        int usedWindowSize = 0;

        for (int num : nums)
        {
            for (int i = 0; i < usedWindowSize; ++i)
            {
                if (window[i].first == num)
                {
                    ++window[i].second;
                    for (int j = i; j > 0; --j)
                    {
                        if (window[j].second > window[j - 1].second)
                        {
                            swap(window[j], window[j - 1]);
                        }
                    }
                    continue;
                }
            }
            if (usedWindowSize < window.size())
            {
                window[usedWindowSize++] = { num, 1 };
            }
            else
            {
                window[usedWindowSize-1] = { num, 1 };
            }
        }

        return window[0].first;
    }
};
