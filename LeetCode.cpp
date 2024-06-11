// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int16_t>> data(m, vector<int16_t>(n, 0));
        int square = 0;

        for (int j = 0; j < n; ++j) {
            data[0][j] = matrix[0][j] - '0';
            square += data[0][j];
        }
        for (int i = 0; i < m; ++i) {
            data[i][0] = matrix[i][0] - '0';
            square += data[i][0];
        }

        square = square > 0;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int v = matrix[i][j] - '0';
                int d = v * (v + min({ data[i - 1][j], data[i][j - 1], data[i - 1][j - 1] }));
                square = max(square, d);
                data[i][j] = d;
            }
        }

        return square * square;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
