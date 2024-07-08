#pragma once

#include <array>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        const int size = int(nums.size());
        k = k % size;
        if (k > 0)
        {
            rotateRightImpl(nums, size, k);
        }
    }

    void rotateRightImpl(vector<int>& nums, int size, int k)
    {
        const int quotient = size / k;
        const int remainder = size % k;

        for (int i = 1; i < quotient; ++i)
        {
            const int offset = k * i;
            for (int j = 0; j < k; ++j)
            {
                swap(nums[j], nums[offset + j]);
            }
        }
        for (int i = 0; i < remainder; ++i)
        {
            swap(nums[i], nums[size - 1 - i]);
        }
        if (remainder > 0)
        {
            rotateRightImpl(nums, k, k - remainder);
        }
    }
};
