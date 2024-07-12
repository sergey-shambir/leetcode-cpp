#pragma once

#include <algorithm>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool wordPattern(string p, string s)
    {
        pattern = p;
        patternPos = 0;
        mapping.clear();
        knownWords.clear();

        const char* spWord = s.data();
        const char* spEnd = s.data() + s.length();
        while (spWord < spEnd)
        {
            const char* spWordEnd = find(spWord, spEnd, ' ');
            if (!consumeWord(string_view(spWord, spWordEnd - spWord)))
            {
                return false;
            }
            spWord = spWordEnd + 1;
        }

        return patternPos == pattern.size();
    }

private:
    bool consumeWord(string_view word)
    {
        if (patternPos >= pattern.size())
        {
            return false;
        }

        char ch = pattern[patternPos++];
        if (const auto it = mapping.find(ch); it != mapping.end())
        {
            if (word != it->second)
            {
                return false;
            }
        }
        else if (knownWords.contains(word))
        {
            return false;
        }
        else
        {
            mapping.emplace(ch, word);
            knownWords.insert(word);
        }
        return true;
    }

    string pattern;
    size_t patternPos = 0;
    unordered_map<char, string_view> mapping;
    unordered_set<string_view> knownWords;
};
