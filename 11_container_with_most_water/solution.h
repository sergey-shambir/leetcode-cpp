#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int waterVolume = 0;

        const int* left = height.data();
        const int* right = height.data() + (height.size() - 1);

        while (left < right)
        {
            const int minHeight = (std::min)(*left, *right);
            const int width = (right - left);
            waterVolume = (std::max)(waterVolume, minHeight * width);

            if (*left < *right)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return waterVolume;
    }
};
