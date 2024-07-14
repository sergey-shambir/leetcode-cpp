#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> results;
        results.reserve(intervals.size() + 1);

        auto left = lower_bound(intervals.begin(), intervals.end(), newInterval, [](const auto& a, const auto &b) {
            return a[1] < b[0];
        });
        auto right = lower_bound(intervals.begin(), intervals.end(), newInterval, [](const auto& a, const auto &b) {
            return a[0] <= b[1];
        });
        if (left != intervals.end())
        {
            newInterval[0] = (min)(newInterval[0], (*left)[0]);
        }
        if (right != intervals.begin())
        {
            newInterval[1] = (max)(newInterval[1], (*prev(right))[1]);
        }

        results.insert(results.end(), intervals.begin(), left);
        results.push_back(newInterval);
        results.insert(results.end(), right, intervals.end());

        return results;
    }
};

