#pragma once

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        return s.length() == t.length() && is_permutation(s.begin(), s.end(), t.begin());
    }
};
