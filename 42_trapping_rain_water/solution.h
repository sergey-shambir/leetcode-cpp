#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        const size_t size = height.size();
        const size_t lastIndex = size - 1;
        
        vector<int> prefixHeight(size, 0);
        vector<int> suffixHeight(size, 0);
    
        for (size_t i = 1; i < size; ++i)
        {
            prefixHeight[i] = (std::max)(prefixHeight[i-1], height[i-1]);
        }
        for (size_t i = lastIndex - 1; i < size; --i)
        {
            suffixHeight[i] = (std::max)(suffixHeight[i+1], height[i+1]);
        }
        int waterVolume = 0;
        for (size_t i = 1; i < lastIndex; ++i)
        {
            const int surroundingHeight = (std::min)(suffixHeight[i], prefixHeight[i]);
            const int diff = surroundingHeight - height[i];
            if (diff > 0)
            {
                waterVolume += diff;
            }
        }
        
        return waterVolume;
    }
};

