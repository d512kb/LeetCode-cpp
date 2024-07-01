// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows, vector<int>(1, 1));

        for (int i = 1; i < numRows; ++i) {
            result[i].assign(i + 1, 1);
            vector<int>& prevRow = result[i - 1];
            vector<int>& row = result[i];
            for (int j = 1; j < i; ++j) {
                row[j] = prevRow[j - 1] + prevRow[j];
            }
        }

        return result;
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}