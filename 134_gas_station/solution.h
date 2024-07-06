#include <stdint.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int sum = 0;
        for (size_t i = 0, stationCount = gas.size(); i < stationCount; ++i)
        {
            gas[i] -= cost[i];
            sum += gas[i];
        }
        if (sum < 0)
        {
            return -1;
        }

        for (size_t i = 0, stationCount = gas.size(); i < stationCount; )
        {
            int remainder = gas[i];
            size_t j = (i + 1) % stationCount;
            for (; remainder >= 0 && j != i; j = (j + 1) % stationCount)
            {
                remainder += gas[j];
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
