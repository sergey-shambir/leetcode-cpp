#pragma once

#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() <= 2)
        {
            return nums.size();
        }

        int* dest = nums.data() + 1;
        for (const int *src = dest, *end = nums.data() + nums.size(); src != end; ++src)
        {
            dest += size_t(*src != *dest) | size_t(*dest != *(dest - 1));
            *dest = *src;
        }
        return dest + 1 - nums.data();
    }
};
