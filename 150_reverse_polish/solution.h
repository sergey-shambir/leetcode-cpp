#include <stdint.h>
#include <string>
#include <vector>
#include <memory>

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

        vector<int> stack;
        stack.reserve(tokens.size());
        for (const auto& token : tokens)
        {
            if (token.length() == 1)
            {
                if (token == add)
                {
                    const auto other = stack.back();
                    stack.pop_back();
                    stack.back() += other;
                    continue;
                }
                if (token == substract)
                {
                    const auto other = stack.back();
                    stack.pop_back();
                    stack.back() -= other;
                    continue;
                }
                if (token == multiply)
                {
                    const auto other = stack.back();
                    stack.pop_back();
                    stack.back() *= other;
                    continue;
                }
                if (token == divide)
                {
                    const auto other = stack.back();
                    stack.pop_back();
                    stack.back() /= other;
                    continue;
                }
            }
            stack.push_back(stoi(token));
        }
        return stack.back();
    }
};
