#pragma once

#include <cstring>
#include <stdexcept>
#include <string>

using namespace std;

// "(1+(4+5+2)-3)+(6+8)"
// 2-1 + 2

class Solution
{
public:
    int calculate(string s)
    {
        p = s.data();
        end = s.data() + s.size();

        return evalExpr();
    }

private:
    int evalExpr()
    {
        int result = evalTerm();
        bool canContinue = true;
        while (canContinue)
        {
            skipSpaces();
            const char op = lookup();
            switch (op)
            {
            case '+':
                advance();
                result += evalTerm();
                break;
            case '-':
                advance();
                result -= evalTerm();
                break;
            default:
                canContinue = false;
                break;
            }
        }
        return result;
    }

    int evalTerm()
    {
        skipSpaces();

        int result = 0;
        if (lookup() == '(')
        {
            advance();
            result = evalExpr();

            skipSpaces();
            if (lookup() != ')')
            {
                throw invalid_argument("unclosed ')'");
            }
            advance();
        }
        else
        {
            result = parseNumber();
        }
        return result;
    }

    int parseNumber()
    {
        skipSpaces();

        int sign = 1;
        if (lookup() == '-')
        {
            sign = -1;
            advance();
        }

        int modulo = 0;
        while (isdigit(lookup()))
        {
            modulo = modulo * 10 + (lookup() - '0');
            advance();
        }
        return sign * modulo;
    }

    char lookup() const
    {
        if (p >= end)
        {
            return '\0';
        }
        return *p;
    }

    void advance()
    {
        ++p;
    }

    void skipSpaces()
    {
        while (p < end && *p == ' ')
        {
            advance();
        }
    }

    const char* p = nullptr;
    const char* end = nullptr;
};
