#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::ranges::sort(intervals);

        vector<vector<int>> results;
        results.push_back(intervals[0]);
        for (const auto &interval : intervals)
        {
            if (results.back()[1] >= interval[0])
            {
                results.back()[1] = (max)(results.back()[1], interval[1]);
            }
            else
            {
                results.push_back(interval);
            }
        }
        return results;
    }
};
