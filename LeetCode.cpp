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

        vector<string> rows(numRows, "");

        int currentRow = 0;
        int rowInc = 1;

        for (int i = 0; i < s.size(); ++i) {
            rows[currentRow] += s[i];
            currentRow += rowInc;

            if (currentRow < 0 || currentRow > numRows - 1) {
                rowInc = -rowInc;
                currentRow += 2 * rowInc;
            }
        }

        string result;

        for (const auto& s : rows) {
            result += s;
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
