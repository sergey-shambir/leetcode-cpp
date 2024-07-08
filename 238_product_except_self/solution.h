#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
    	const int size = nums.size();
    	vector<int> prefixes(size, 0);
    	vector<int> suffixes(size, 0);
    	vector<int> answer(size, 0);
    	
    	int value = 1;
    	for (size_t i = 0; i < size; ++i)
    	{
    	    value *= nums[i];
    	    prefixes[i] = value;
    	}
    	
    	value = 1;
    	for (size_t i = (size - 1); i < size; --i)
    	{
    	    value *= nums[i];
    	    suffixes[i] = value;
    	}

        answer[0] = suffixes[1];
        answer[size-1] = prefixes[size-2];
    	for (size_t i = 1; i < size - 1; ++i)
    	{
    	    answer[i] = prefixes[i-1] * suffixes[i+1];
    	}

        return answer;
    }
};
