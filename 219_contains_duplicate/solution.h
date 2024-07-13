#pragma once

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,size_t> numIndexMap;
        for (size_t i = 0, iEnd = nums.size(); i < iEnd; ++i)
        {
            const int num = nums[i];
            if (const auto it = numIndexMap.find(num); it != numIndexMap.end())
            {
                if (i - it->second <= size_t(k))
                {
                    return true;
                }
            }
            numIndexMap[num] = i;
        }
        return false;
    }
};
