#include <vector>
#include <limits>
#include <algorithm>

class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
        {
            return 0;
        }

        std::vector<int> digits = to_digits(x);
        std::vector<int> reversed = reverse_number(digits);

        if (x > 0)
        {
            if (is_greater(reversed, to_digits(std::numeric_limits<int>::max())))
            {
                return 0;
            }
            return from_digits(reversed, 1);
        }
        else
        {
            if (is_greater(reversed, to_digits(std::numeric_limits<int>::min())))
            {
                return 0;
            }
            return from_digits(reversed, -1);
        }
    }

private:
    bool is_greater(const std::vector<int>& left, const std::vector<int>& right)
    {
        if (left.size() > right.size())
        {
            return true;
        }
        if (left.size() < right.size())
        {
            return false;
        }
        for (size_t i = left.size() - 1, iMax = left.size(); i < iMax; --i)
        {
            if (left[i] > right[i])
            {
                return true;
            }
            if (left[i] < right[i])
            {
                return false;
            }
        }
        return false;
    }

    std::vector<int> reverse_number(const std::vector<int>& digits)
    {
        std::vector<int> result = digits;
        while (result.size() > 1 && result.back() == 0)
        {
            result.pop_back();
        }

        std::reverse(result.begin(), result.end());
        return result;
    }

    std::vector<int> to_digits(int x)
    {
        if (x > 0)
        {
            return to_digits(-x);
        }

        std::vector<int> digits;
        digits.reserve(10);
        while (x)
        {
            digits.push_back(-(x % 10));
            x /= 10;
        }
        return digits;
    }

    int from_digits(std::vector<int> digits, int sign)
    {
        int result = 0;
        for (size_t i = digits.size() - 1, iMax = digits.size(); i < iMax; --i)
        {
            result *= 10;
            result += sign * digits[i];
        }
        return result;
    }
};
