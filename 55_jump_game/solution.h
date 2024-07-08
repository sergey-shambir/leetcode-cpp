#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        vector<bool> achievability(nums.size(), false);
        int lastIndex = int(nums.size() - 1);
        achievability[lastIndex] = true;

        for (int i = lastIndex - 1; i >= 0; --i)
        {
            for (int j = i + 1, maxJ = (std::min)(i + nums[i], lastIndex); j <= maxJ; ++j)
            {
                if (achievability[j])
                {
                    achievability[i] = true;
                    break;
                }
            }
        }
        return achievability[0];
    }
};
