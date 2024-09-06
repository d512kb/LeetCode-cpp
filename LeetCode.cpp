// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size() - 1;
        int sz = matrix.size();
        int row = 0;

        while (row < sz && col >= 0) {
            int val = matrix[row][col];

            if (val < target) {
                ++row;
            } else if (val > target) {
                --col;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}