#pragma once

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        std::ranges::sort(points);

        int shotCount = 1;

        int burstRight = points.front()[1];
        for (auto it = points.begin(), endIt = points.end(); it < endIt; ++it)
        {
            const int left = (*it)[0];
            const int right = (*it)[1];
            if (left > burstRight)
            {
                burstRight = right;
                ++shotCount;
            }
            else
            {
                burstRight = (min)(burstRight, right);
            }
        }

        return shotCount;
    }
};
