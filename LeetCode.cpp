// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() / 2; ++i) {
            int b = matrix.size() - i - 1;
            for (int j = i; j < b; ++j) {
                int t = matrix[i][j];
                swap(t, matrix[j][b]);
                swap(t, matrix[b][b - j + i]);
                swap(t, matrix[b - j + i][i]);
                swap(t, matrix[i][j]);
            }
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
