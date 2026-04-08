// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const int rows = img.size();
        const int cols = img.front().size();

        vector<vector<int>> result(rows, vector<int>(cols));

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int num = 0;
                int cells = 0;

                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        int newRow = row + i;
                        int newCol = col + j;

                        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                            num += img[newRow][newCol];
                            ++cells;
                        }
                    }
                }

                result[row][col] = num / cells;
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}