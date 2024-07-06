#pragma once

#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        size_t destI = 0;
        for (size_t srcI = 1, size = nums.size(); srcI < size; ++srcI)
        {
            destI += size_t(nums[srcI] != nums[destI]);
            nums[destI] = nums[srcI];
        }
        return destI + 1;
    }
};
