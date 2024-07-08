#pragma once

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::ranges::sort(citations, std::greater<int>());
        for (int i = 0; i < int(citations.size()); ++i)
        {
            if (citations[i] < i + 1)
            {
                return i;
            }
        }
        return int(citations.size());
    }
};
