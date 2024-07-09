#pragma once

#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
    	const char *left = s.data();
    	const char *right = s.data() + (s.size() - 1);
    	for (;;)
    	{
    	    while (left < right && !isalnum(*left))
    	    {
    	        ++left;
    	    }
    	    while (left < right && !isalnum(*right))
    	    {
    	        --right;
    	    }
    	    if (left >= right)
    	    {
    	        return true;
    	    }
    	    if (tolower(*left) != tolower(*right))
    	    {
    	        return false;
    	    }
    	    ++left;
    	    --right;
    	}
    }
};
