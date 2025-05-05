#include <cstdint>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        return isPalindromeImpl(static_cast<uint64_t>(x));
    }

private:
    bool isPalindromeImpl(uint64_t x)
    {
        uint64_t top = 1;
        while (x >= top * 10)
        {
            top *= 10;
        }

        while (top >= 10)
        {
            if (x / top != x % 10)
            {
                return false;
            }
            x = (x % top) / 10;
            top = top / 100;
        }

        return true;
    }
};