#pragma once

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> results;
        size_t posStart = std::lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        size_t neg = posStart - 1, pos = posStart;
        while (neg < nums.size() && pos < nums.size()) {
            if (nums[pos] < -nums[neg]) {
                results.push_back(nums[pos]*nums[pos]);
                ++pos;
            }
            else
            {
                results.push_back(nums[neg]*nums[neg]);
                --neg;
            }
            
        }
        while (neg < nums.size()) {
            results.push_back(nums[neg]*nums[neg]);
                --neg;
        }
        while (pos < nums.size()) {
            results.push_back(nums[pos]*nums[pos]);
                ++pos;
        }
        return results;
    }
};