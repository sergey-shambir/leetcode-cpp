#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    Solution()
    {
        _lettersMap = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }

        _buffer = digits;
        _results.clear();
        _results.reserve(static_cast<size_t>(std::pow(3, digits.size())));

        addLetterCombinationsRecursive(digits, 0);

        return _results;
    }

private:
    void addLetterCombinationsRecursive(const std::string& digits, size_t i)
    {
        size_t index = digits[i] - '2';
        const std::string& letters = _lettersMap[index];
        for (char ch : letters)
        {
            _buffer[i] = ch;
            if (i + 1 == digits.size())
            {
                _results.push_back(_buffer);
            }
            else
            {
                addLetterCombinationsRecursive(digits, i + 1);
            }
        }
    }

    string _buffer;
    vector<string> _results;
    std::vector<std::string> _lettersMap;
};
