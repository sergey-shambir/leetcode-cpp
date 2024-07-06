#pragma once

#include <vector>
#include <memory.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int size1, vector<int>& nums2, int size2)
    {
        if (size2 == 0)
        {
            return;
        }
        if (size1 == 0)
        {
            std::swap(nums1, nums2);
            return;
        }

        // Переместим значения в nums1 вправо
        const int totalSize = size1 + size2;
        for (int i = size1 - 1; i >= 0; --i)
        {
            nums1[size2 + i] = nums1[i];
        }

        int i1 = size2;
        int i2 = 0;
        int iOut = 0;
        while (i1 < totalSize && i2 < size2)
        {
            if (nums1[i1] < nums2[i2])
            {
                nums1[iOut++] = nums1[i1++];
            }
            else
            {
                nums1[iOut++] = nums2[i2++];
            }
        }
        while (i1 < totalSize)
        {
            nums1[iOut++] = nums1[i1++];
        }
        while (i2 < size2)
        {
            nums1[iOut++] = nums2[i2++];
        }
    }
};
