// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool colZero = false;

        for (int r = 0; r < matrix.size(); ++r) {
            if (matrix[r][0] == 0) {
                colZero = true;
            }

            for (int c = 1; c < matrix.front().size(); ++c) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }

        for (int r = matrix.size() - 1; r >= 0; --r) {
            for (int c = 1; c < matrix.front().size(); ++c) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }

            if (colZero) {
                matrix[r][0] = 0;
            }
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
