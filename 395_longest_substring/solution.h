
// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

#include <string>
#include <string_view>
#include <unordered_map>

class Solution {
public:
    int longestSubstring(std::string s, int k) {
        return longestSubstringImpl(s, k);
    }

private:
    int longestSubstringImpl(std::string_view s, int k) {
        if (s.size() < static_cast<size_t>(k))
        {
            return 0;
        }

        std::unordered_map<char, int> frequencies;
        for (char c : s)
        {
            frequencies[c]++;
        }

        bool isLongest = true;
        for (const auto &kv : frequencies)
        {
            if (kv.second < k)
            {
                isLongest = false;
                break;
            }
        }

        if (isLongest)
        {
            return static_cast<int>(s.size());
        }

        int result = 0;
        size_t left = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            int frequency = frequencies[s[i]];
            if (frequency < k)
            {
                int candidate = longestSubstringImpl(s.substr(left, i - left), k);
                result = (std::max)(result, candidate);
                left = i + 1;
            }
        }

        result = (std::max)(result, longestSubstringImpl(s.substr(left), k));

        return result;
    }

};