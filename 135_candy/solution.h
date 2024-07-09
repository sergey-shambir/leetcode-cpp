#include <vector>

using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        const int size = ratings.size();
        const int lastIndex = size - 1;

        vector<int> candies(size, 1);
        for (size_t i = 1; i < size; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (size_t i = lastIndex - 1; i < size; --i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = (std::max)(candies[i], candies[i + 1] + 1);
            }
        }

        int candiesTotal = 0;
        for (int c : candies)
        {
            candiesTotal += c;
        }

        return candiesTotal;
    }
};
