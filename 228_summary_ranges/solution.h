#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> results;
        if (nums.empty())
        {
            return results;
        }

        const size_t size = nums.size();
        size_t iStart = 0;
        size_t i = 1;
        for (; i < size; ++i)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                addRange(results, nums[iStart], nums[i - 1]);
                iStart = i;
            }
        }
        addRange(results, nums[iStart], nums[size - 1]);

        return results;
    }

private:
    void addRange(vector<string>& ranges, int start, int last)
    {
        if (start == last)
        {
            ranges.push_back(to_string(start));
        }
        else
        {
            ranges.push_back(to_string(start) + "->" + to_string(last));
        }
    }
};
