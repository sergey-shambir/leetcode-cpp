#include <vector>
#include <string>
#include <span>

class Solution {
    struct Token
    {
        char ch = '0';
        bool repeated = false;

        Token(char ch, bool repeated)
            : ch(ch), repeated(repeated)
        {
        }

        bool isMatch(char other)
        {
            return ch == other || ch == '.';
        }
    };

public:
    bool isMatch(std::string s, std::string p) {
        std::vector<Token> pattern = tokenizePattern(p);
        optimizePattern(pattern);

        return isMatch(s, pattern);
    }

private:
    bool isMatch(std::string_view text, std::span<Token> pattern)
    {
        if (text.empty() || pattern.empty())
        {
            return text.empty() || pattern.empty();
        }

        if (pattern[0].isMatch(text[0]))
        {
            if (isMatch(text.substr(1), pattern.subspan(1)))
            {
                return true;
            }
            if (pattern[0].repeated && isMatch(text.substr(1), pattern))
            {
                return true;
            }
        }
        if (pattern[0].repeated && isMatch(text, pattern.subspan(1)))
        {
            return true;
        }
        return false;
    }

    void optimizePattern(std::vector<Token> &tokens)
    {
        for (size_t i = 1; i < tokens.size(); ++i)
        {
            if (tokens[i - 1].ch == tokens[i].ch && tokens[i - 1].repeated)
            {
                if (tokens[i].repeated)
                {
                    tokens.erase(tokens.begin() + i);
                    --i;
                }
                else
                {
                    std::swap(tokens[i - 1], tokens[i]);
                }
            }
        }
    }

    std::vector<Token> tokenizePattern(const std::string &pattern)
    {
        std::vector<Token> result;
        result.reserve(pattern.size());

        for (char ch : pattern)
        {
            if (ch == '*')
            {
                result.back().repeated = true;
            }
            else
            {
                result.push_back(Token(ch, false));
            }
        }
        return result;
    }
};