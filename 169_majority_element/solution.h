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
        int windowTop = -1;

        for (int num : nums)
        {
            bool inWindow = false;
            for (int i = 0; i <= windowTop; ++i)
            {
                if (window[i].first == num)
                {
                    inWindow = true;
                    ++(window[i].second);
                    for (; i > 0; --i)
                    {
                        if (window[i].second > window[i - 1].second)
                        {
                            swap(window[i - 1], window[i]);
                        }
                    }
                    break;
                }
            }
            if (!inWindow)
            {
                if (windowTop + 1 < window.size())
                {
                    ++windowTop;
                }
                window[windowTop] = { num, 1 };
            }
        }

        return window[0].first;
    }
};
