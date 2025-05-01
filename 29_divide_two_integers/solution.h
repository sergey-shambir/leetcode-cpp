#pragma once

#include <limits>
#include <stack>
#include <vector>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 0)
        {
            return std::numeric_limits<int>::max();
        }
        if (divisor == 1)
        {
            return dividend;
        }
        if (divisor == -1)
        {
            return dividend == std::numeric_limits<int>::min() ? std::numeric_limits<int>::max() : -dividend;
        }
        if (dividend == std::numeric_limits<int>::min() && divisor == -1)
        {
            return std::numeric_limits<int>::max();
        }
        if (divisor == std::numeric_limits<int>::min())
        {
            return dividend == std::numeric_limits<int>::min() ? 1 : 0;
        }

        if (dividend < 0)
        {
            if (divisor < 0)
            {
                return divideNegativeToNegative(dividend, divisor);
            }
            else
            {
                return -divideNegativeToNegative(dividend, -divisor);
            }
        }
        else
        {
            if (divisor < 0)
            {
                return -dividePositiveToPositive(dividend, -divisor);
            }
            else
            {
                return dividePositiveToPositive(dividend, divisor);
            }
        }
    }

private:
    int divideNegativeToNegative(int dividend, int divisor)
    {
        std::stack<int> divisors;
        divisors.push(divisor);

        while (dividend - divisor <= divisor)
        {
            divisor += divisor;
            divisors.push(divisor);
        }

        int quotient = 0;
        while (!divisors.empty())
        {
            quotient += quotient;
            if (dividend <= divisors.top())
            {
                dividend -= divisors.top();
                quotient++;
            }
            divisors.pop();
        }

        return quotient;
    }

    int dividePositiveToPositive(int dividend, int divisor)
    {
        std::stack<int> divisors;
        divisors.push(divisor);

        while (dividend - divisor >= divisor)
        {
            divisor += divisor;
            divisors.push(divisor);
        }

        int quotient = 0;
        while (!divisors.empty())
        {
            quotient += quotient;
            if (dividend >= divisors.top())
            {
                dividend -= divisors.top();
                quotient++;
            }
            divisors.pop();
        }

        return quotient;
    }
};