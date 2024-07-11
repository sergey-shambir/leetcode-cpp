#pragma once

#include <array>
#include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        vector<int> prefixSum;
        prefixSum.reserve(nums.size());

        prefixSum.push_back(nums[0]);
        for (const int *numsPtr = nums.data() + 1, *numsEnd = nums.data() + nums.size(); numsPtr < numsEnd; ++numsPtr)
        {
            prefixSum.push_back(prefixSum.back() + *numsPtr);
        }

        int result = int(nums.size()) + 1;

        const int* prefixBegin = prefixSum.data();
        const int* prefixEnd = prefixSum.data() + prefixSum.size();
        const int* right = lower_bound(prefixBegin, prefixEnd, target);
        for (; right < prefixEnd; ++right)
        {
            const int carry = *right - target;
            const int* left = lower_bound(prefixBegin, right, carry);
            if (*left > carry)
            {
                left = left - 1;
            }
            result = min<int>(result, right - left);
        }

        return result <= int(nums.size()) ? result : 0;
    }
};
