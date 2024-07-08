#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        vector<int> jumpCount(nums.size(), -1);
        int lastIndex = int(jumpCount.size()) - 1;
        jumpCount[lastIndex] = 0;
        for (int i = lastIndex - 1; i >= 0; --i)
        {
            for (int j = (std::min)(lastIndex, i + nums[i]); j > i; --j)
            {
                if (jumpCount[j] < 0)
                {
                    continue;
                }
                int jumps = jumpCount[j] + 1;
                if (jumpCount[i] < 0 || jumpCount[i] > jumps)
                {
                    jumpCount[i] = jumps;
                }
            }
        }
        return jumpCount[0];
    }
};
