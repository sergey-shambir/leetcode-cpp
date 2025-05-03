#include <string>
#include <cstdint>
#include <limits>

using namespace std;

class Solution {
    public:
        int myAtoi(string s) {
            size_t i = 0;
            while (i < s.size() && s[i] == ' ')
            {
                ++i;
            }
            if (i == s.size())
            {
                return 0;
            }
    
            int64_t sign = 1;
            switch (s[i])
            {
                case '-':
                    sign = -1;
                    ++i;
                    break;
                case '+':
                    ++i;
                    break;
                default:
                    break;
            }
    
            int64_t value = 0;
            while (i < s.size() && isdigit(s[i]))
            {
                value = 10 * value + sign * (s[i] - '0');
    
                if (value < std::numeric_limits<int>::min())
                {
                    return std::numeric_limits<int>::min();
                }
                else if (value > std::numeric_limits<int>::max())
                {
                    return std::numeric_limits<int>::max();
                }
                ++i;
            }
    
            return value;
        }
    };