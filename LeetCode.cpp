// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> nextBoard(board);
        int rMax = board.size() - 1;
        int cMax = board.front().size() - 1;

        vector<pair<int, int>> dirs{ {-1,-1},{-1,0},{-1, 1}, {0,-1}, {0,1}, {1,-1},{1,0},{1,1} };

        for (int r = 0; r <= rMax; ++r) {
            for (int c = 0; c <= cMax; ++c) {
                int n = 0;

                for (const auto& dir : dirs) {
                    int rc = r + dir.first;
                    int cc = c + dir.second;

                    if (rc >= 0 && rc <= rMax && cc >= 0 && cc <= cMax)
                        n += board[rc][cc];
                }

                if (board[r][c] == 0) {
                    nextBoard[r][c] = n == 3;
                } else {
                    nextBoard[r][c] = n > 1 && n < 4;
                }
            }
        }

        board = nextBoard;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
