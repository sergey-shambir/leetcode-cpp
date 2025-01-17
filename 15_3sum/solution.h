#pragma once

#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        // Sort to use binary search.
        sort(nums.begin(), nums.end());

        set<vector<int>> results;
        vector<int> nextResult(3, 0);

        const int* pEnd = nums.data() + nums.size();
        for (const int* p1 = nums.data(); p1 < pEnd; ++p1)
        {
            nextResult[0] = *p1;
            for (const int* p2 = p1 + 1; p2 < pEnd; ++p2)
            {
                nextResult[1] = *p2;

                const int needle = -(*p1 + *p2);
                const auto it = std::lower_bound(p2 + 1, pEnd, needle);
                if (it != pEnd && *it == needle)
                {
                    nextResult[2] = needle;
                    if (!results.contains(nextResult))
                    {
                        results.insert(nextResult);
                    }
                }
            }
        }

        return vector<vector<int>>(results.begin(), results.end());
    }
};
