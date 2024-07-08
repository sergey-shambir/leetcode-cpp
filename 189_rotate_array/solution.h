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
            rotateRightImpl(nums.data(), nums.data() + size, k);
        }
    }

    void rotateRightImpl(int* begin, int* end, int k)
    {
        const int size = end - begin;
        if (k > size / 2)
        {
            rotateLeftImpl(begin, end, size - k);
            return;
        }

        const int quotient = size / k;
        const int remainder = size % k;

        for (int i = 1; i < quotient; ++i)
        {
            const int offset = k * i;
            for (int j = 0; j < k; ++j)
            {
                swap(begin[j], begin[offset + j]);
            }
        }
        for (int i = 0; i < remainder; ++i)
        {
            swap(begin[i], begin[size - remainder + i]);
        }
        if (remainder > 0)
        {
            rotateRightImpl(begin, begin + k, k - remainder);
        }
    }

    void rotateLeftImpl(int* begin, int* end, int k)
    {
        const int size = end - begin;
        if (k > size / 2)
        {
            rotateRightImpl(begin, end, size - k);
            return;
        }

        const int quotient = size / k;
        const int remainder = size % k;

        for (int i = 1; i < quotient; ++i)
        {
            const int offset = k * i;
            for (int j = 0; j < k; ++j)
            {
                swap(begin[size - 1 - j], begin[size - 1 - (offset + j)]);
            }
        }
        for (int i = 0; i < remainder; ++i)
        {
            swap(begin[size - 1 - i], begin[remainder - i - 1]);
        }
        if (remainder > 0)
        {
            rotateLeftImpl(end - k, end, k - remainder);
        }
    }
};
