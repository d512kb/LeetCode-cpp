// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        const int rows = board.size();
        const int cols = board.front().size();
        int ans = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 'X') {
                    if ((row == 0 || board[row - 1][col] == '.') && (col == 0 || board[row][col - 1] == '.')) {
                        ++ans;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}