#pragma once

#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int valCount = 0;
        for (size_t srcI = 0, size = nums.size(); srcI < size; ++srcI)
        {
            if (nums[srcI] == val)
            {
                valCount += 1;
            }
            else
            {
                nums[srcI - valCount] = nums[srcI];
            }
        }

        return int(nums.size()) - valCount;
    }
};
