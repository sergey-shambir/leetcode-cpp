#pragma once

#include <vector>
#include <stdexcept>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        const int* const begin = numbers.data();
        const int* left = numbers.data();
        const int* right = numbers.data() + (numbers.size() - 1);
        while (left < right)
        {
            const int sum = *left + *right;
            if (sum == target)
            {
                return vector<int>{ int(left - begin + 1), int(right - begin + 1) };
            }
            if (sum < target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        throw std::logic_error("no solution");
    }
};
