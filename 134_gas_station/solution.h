#include <vector>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        for (size_t i = 0, iMax = gas.size(); i < iMax; ++i)
        {
            gas[i] -= cost[i];
            sum += gas[i];
        }
        if (sum < 0)
        {
            return -1;
        }

        for (size_t i = 0, stationCount = gas.size(); i < stationCount; ++i)
        {
            int remainder = gas[i];
            for (size_t j = i + 1; remainder >= 0 && j != i; j = (j + 1) % stationCount)
            {
                remainder += gas[j];
            }
            if (remainder >= 0)
            {
                return i;
            }
        }

        return -1;
    }
};
