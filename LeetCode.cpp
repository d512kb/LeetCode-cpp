// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int firstRowIndex = 0;
        int lastRowIndex = matrix.size() - 1;
        int firstColIndex = 0;
        int lastColIndex = matrix.front().size() - 1;

        vector<int> result;
        int n = matrix.size() * matrix.front().size();
        result.reserve(n);

        while (n > 0) {
            for (int i = firstColIndex; i <= lastColIndex && n > 0; ++i, --n) {
                result.push_back(matrix[firstRowIndex][i]);
            }
            ++firstRowIndex;
            for (int i = firstRowIndex; i <= lastRowIndex && n > 0; ++i, --n) {
                result.push_back(matrix[i][lastColIndex]);
            }
            --lastColIndex;
            for (int i = lastColIndex; i >= firstColIndex && n > 0; --i, --n) {
                result.push_back(matrix[lastRowIndex][i]);
            }
            --lastRowIndex;
            for (int i = lastRowIndex; i >= firstRowIndex && n > 0; --i, --n) {
                result.push_back(matrix[i][firstColIndex]);
            }
            ++firstColIndex;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
