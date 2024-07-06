#include <stdint.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int sum = 0;
        std::vector<int> diffs(gas.size(), 0);
        for (size_t i = 0, stationCount = diffs.size(); i < stationCount; ++i)
        {
            diffs[i] = gas[i] - cost[i];
            sum += diffs[i];
        }
        if (sum < 0)
        {
            return -1;
        }

        for (size_t i = 0, stationCount = diffs.size(); i < stationCount;)
        {
            int remainder = diffs[i];
            size_t j = (i + 1) % stationCount;
            for (; remainder >= 0 && j != i; j = (j + 1) % stationCount)
            {
                remainder += diffs[j];
            }
            if (remainder >= 0)
            {
                return i;
            }
            else
            {
                i = j;
            }
        }

        return -1;
    }
};
