#include <algorithm>
#include <array>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        size_t result = 0;
        std::array<size_t, 256> chars;
        std::fill(chars.begin(), chars.end(), std::string::npos);

        size_t left = 0;
        size_t right = 0;
        size_t length = s.length();

        while (right < length)
        {
            char ch = s[right];
            const size_t position = chars[ch];
            if (position != std::string::npos)
            {
                left = (std::max<size_t>(left, position + 1));
            }
            result = (std::max<size_t>)(result, right - left + 1);
            chars[ch] = right;
            ++right;
        }

        return static_cast<int>(result);
    }
};
