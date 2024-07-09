#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
    	reset();

    	for (const auto& word : words)
    	{
    	    int newMinWidth = nextLineMinWidth > 0 ? (nextLineMinWidth + 1 + word.length()) : word.length();
    	    if (newMinWidth > maxWidth)
    	    {
    	        commitWithJustification(maxWidth);
    	        nextLineMinWidth = word.length();
    	    }
    	    else
    	    {
    	        nextLineMinWidth = newMinWidth;
    	    }
    	    nextLineWords.push_back(word);
    	}
    	commitWithAlighLeft(maxWidth);

        return lines;
    }
    
private:
    void reset()
    {
    	lines.clear();
    	nextLineWords.clear();
    	nextLineMinWidth = 0;
    }
    
    void commitWithAlighLeft(int maxWidth)
    {
        if (nextLineWords.empty())
        {
            return;
        }
        string line;
        for (const auto &word : nextLineWords)
        {
            if (!line.empty())
            {
                line += string(1, ' ');
            }
            line += word;
        }
        if (line.size() < size_t(maxWidth))
        {
            line += string(size_t(maxWidth) - line.size(), ' ');
        }
        commitLine(std::move(line));
    }

    void commitWithJustification(int maxWidth)
    {
        if (nextLineWords.size() <= 1)
        {
            commitWithAlighLeft(maxWidth);
            return;
        }

        int wordCount = int(nextLineWords.size());
        int extraSpaces = maxWidth - nextLineMinWidth;
        int quotient = extraSpaces / (wordCount-1);
        int remainder = extraSpaces % (wordCount-1);
        
        string line;
        for (const auto &word : nextLineWords)
        {
            if (!line.empty())
            {
                int spaceCount = 1 + quotient;
                if (remainder > 0)
                {
                    ++spaceCount;
                    --remainder;
                }
                line += string(spaceCount, ' ');
            }
            line += word;
        }
        commitLine(std::move(line));
    }

    void commitLine(string &&line)
    {
        lines.emplace_back(std::move(line));
        nextLineWords.clear();
        nextLineMinWidth = 0;
    }

    vector<string> lines;
    vector<string> nextLineWords;
    int nextLineMinWidth = 0;
};
