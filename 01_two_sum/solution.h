#pragma once

#include <algorithm>
#include <vector>
#include <stdexcept>

using namespace std;

class Solution
{
    struct OrderedNumber
    {
        int value;
        size_t index;

        auto operator<=>(const OrderedNumber& other) const
        {
            return value <=> other.value;
        }
    };

public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<OrderedNumber> sortedNums(nums.size());
        for (size_t i = 0, iEnd = sortedNums.size(); i < iEnd; ++i)
        {
            sortedNums[i] = OrderedNumber(nums[i], i);
        }

        sort(sortedNums.begin(), sortedNums.end());

        const OrderedNumber* pEnd = sortedNums.data() + sortedNums.size();
        for (const OrderedNumber* p1 = sortedNums.data(); p1 < pEnd; ++p1)
        {
            const int num2 = target - p1->value;
            const OrderedNumber* p2 = lower_bound(p1 + 1, pEnd, OrderedNumber(num2, 0));
            if (p2 != pEnd && p2->value == num2)
            {
                return vector<int>{ int(p1->index), int(p2->index) };
            }
        }

        throw logic_error("no solution at given array");
    }
};
