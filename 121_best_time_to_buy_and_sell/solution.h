#pragma once

#include <array>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int price : prices)
        {
            int profit = price - minPrice;
            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
            if (price < minPrice)
            {
                minPrice = price;
            }
        }

        return maxProfit;
    }
};
