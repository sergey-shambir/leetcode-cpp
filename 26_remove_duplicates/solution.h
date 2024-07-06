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

        int* dest = nums.data();
        for (const int *src = nums.data(), *end = nums.data() + nums.size(); src != end; ++src)
        {
            dest += size_t(*src != *dest);
            *dest = *src;
        }
        return dest + 1 - nums.data();
    }
};
