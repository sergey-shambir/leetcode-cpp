#include <memory>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        const string add{ "+" };
        const string substract{ "-" };
        const string multiply{ "*" };
        const string divide{ "/" };

        unique_ptr<int[]> stack(new int[tokens.size()]);
        int top = -1;

        for (const auto& token : tokens)
        {
            if (token.length() == 1)
            {
                if (token == add)
                {
                    const auto other = stack[top--];
                    stack[top] += other;
                    continue;
                }
                if (token == substract)
                {
                    const auto other = stack[top--];
                    stack[top] -= other;
                    continue;
                }
                if (token == multiply)
                {
                    const auto other = stack[top--];
                    stack[top] *= other;
                    continue;
                }
                if (token == divide)
                {
                    const auto other = stack[top--];
                    stack[top] /= other;
                    continue;
                }
            }
            int value = 0;
            int sign = 1;
            size_t from = 0;
            if (token[0] == '-')
            {
                sign = -1;
                from = 1;
            }
            for (size_t i = from, to = token.size(); i < to; ++i)
            {
                value = value * 10 + (token[i] - '0');
            }
            stack[++top] = sign * value;
        }
        return stack[top];
    }
};
