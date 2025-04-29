#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Генерирует всевозможные комбинации n пар скобок, являющихся корректными скобочными последовательностями.
    vector<string> generateParenthesis(int n) {
        results.clear();
        current = string(2 * n, ')');
        generateParenthesisImpl(0, 2 * n);
        return results;
    }

private:
    void generateParenthesisImpl(int opened, int left) {
        if (left == 1 && opened == 1)
        {
            results.push_back(current);
        }
        if (opened)
        {
            current[current.size() - left] = ')';
            generateParenthesisImpl(opened - 1, left - 1);
        }
        if (opened <= left - 2)
        {
            current[current.size() - left] = '(';
            generateParenthesisImpl(opened + 1, left - 1);
        }
    }

    vector<string> results;
    string current;
};

