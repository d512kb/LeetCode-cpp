// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        string result(s.size(), ' ');
        int jInc = 2 * (numRows - 1);
        int resultIndex = 0;
        int currentLine = 0;

        for (int j = currentLine; j < s.size(); j += jInc) {
            result[resultIndex++] = s[j];
        }

        for (currentLine = 1; currentLine < numRows - 1; ++currentLine) {
            int jMed = jInc - 2 * currentLine;
            for (int j = currentLine; j < s.size(); j += jInc) {
                result[resultIndex++] = s[j];

                if (j + jMed < s.size()) {
                    result[resultIndex++] = s[j + jMed];
                }
            }
        }

        for (int j = currentLine; j < s.size(); j += jInc) {
            result[resultIndex++] = s[j];
        }

        return result;
    }
};

int main() {
    string s;

    for (int i = 0; i < 10000000; ++i) {
        s += 'A';
    }

    Solution sol;
    
    INIT_TIME(timer);

    auto result = sol.convert(s, 1000);

    PRINT_ELAPSED(timer);
    return 0;
}
