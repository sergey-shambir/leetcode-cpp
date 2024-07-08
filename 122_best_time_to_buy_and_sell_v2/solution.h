#pragma once

#include <array>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int totalProfit = 0;
        int minPriceIndex = 0;

        const int maxI = int(prices.size()) - 1;
        for (size_t i = 1; i <= maxI; ++i)
        {
            if (prices[i] >= prices[i - 1])
            {
                continue;
            }
            if (prices[minPriceIndex] < prices[i - 1])
            {
                totalProfit += prices[i - 1] - prices[minPriceIndex];
            }
            minPriceIndex = i;
        }
        if (prices[minPriceIndex] < prices[maxI])
        {
            totalProfit += prices[maxI] - prices[minPriceIndex];
        }

        return totalProfit;
    }
};
