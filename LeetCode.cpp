// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 0) { continue; }

                int top = rows * cols;
                int left = top;

                if (row > 0) { top = mat[row - 1][col]; }
                if (col > 0) { left = mat[row][col - 1]; }

                mat[row][col] = 1 + min(top, left);
            }
        }

        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                int& val = mat[row][col];

                if (val == 0) { continue; }

                int bottom = rows * cols;
                int right = bottom;

                if (row + 1 < rows) { bottom = mat[row + 1][col]; }
                if (col + 1 < cols) { right = mat[row][col + 1]; }

                val = min(val, 1 + min(bottom, right));
            }
        }

        return mat;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}