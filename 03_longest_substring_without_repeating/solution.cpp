#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        _chars.reserve((std::min<size_t>)(256, s.length()));

        for (size_t start = 0, length = s.length(); start < length; ++start)
        {
            for (size_t i = start; i < length; ++i)
            {
                char ch = s[i];
                const auto it = _chars.find(ch);
                if (it == _chars.end())
                {
                    _result = (std::max<size_t>)(_result, i - start + 1);
                    _chars[ch] = i;
                }
                else
                {
                    start = it->second;
                    _chars.clear();
                    break;
                }
            }
        }

        return static_cast<int>(_result);
    }

private:
    size_t _result = 0;
    std::unordered_map<char, size_t> _chars;
};
