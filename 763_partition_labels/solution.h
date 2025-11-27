#pragma once

#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::unordered_map<char, size_t> rightmostIndexMap;
        for (size_t i = 0, size = s.size(); i < size; ++i)
        {
            rightmostIndexMap[s[i]] = i;
        }

        std::vector<int> results;
        for (size_t left = 0, size = s.size(); left < size;)
        {
            size_t right = rightmostIndexMap[s[left]];
            for (size_t i = left + 1; i < right; ++i)
            {
                right = (std::max)(right, rightmostIndexMap[s[i]]);
            }
            results.push_back(static_cast<int>(right - left + 1));
            left = right + 1;
        }

        return results;
    }
};