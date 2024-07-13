#pragma once

#include <unordered_set>

using namespace std;

// 99 -> false
// 19 -> true


class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visitedNumbers;

        while (n != 1)
        {
            if (visitedNumbers.contains(n))
            {
                return false;
            }
            visitedNumbers.insert(n);
            n = getSquaredDigitsSum(n);
        }
        return true;
    }

private:
    static int getSquaredDigitsSum(int n)
    {
        int result = 0;
        while (n > 0)
        {
            const int digit = (n % 10);
            result += digit * digit;
            n /= 10;
        }
        return result;
    }
};
