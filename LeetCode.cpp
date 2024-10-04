// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> paths(rows, vector<int>(cols));

        int result = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                result = max(result, dfs(matrix, paths, row, col, -1));
            }
        }

        return result;
    }
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& paths, int row, int col, int prev) {
        if (row < 0 || row == matrix.size() || col < 0 || col == matrix[0].size()) { return 0; }
        if (matrix[row][col] <= prev) { return 0; }
        if (paths[row][col] != 0) { return paths[row][col]; }

        int currValue = matrix[row][col];

        int len = max(max(max(dfs(matrix, paths, row - 1, col, currValue),
                              dfs(matrix, paths, row, col + 1, currValue)),
                          dfs(matrix, paths, row + 1, col, currValue)),
                      dfs(matrix, paths, row, col - 1, currValue));

        return paths[row][col] = len + 1;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}