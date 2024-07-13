#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> anagrams;
        for (const auto& str : strs)
        {
            string key = str;
            std::ranges::sort(key);
            anagrams[key].push_back(str);
        }

        vector<vector<string>> results;
        results.reserve(anagrams.size());
        for (auto& kv : anagrams)
        {
            results.emplace_back(kv.second);
        }
        return results;
    }
};
