// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.front().size(); ++j) {
                if (board[i][j] == 'O') {
                    vector<pair<int, int>> cells;
                    if (checkRegion(board, cells, i, j)) {
                        for (const auto& p : cells) {
                            board[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }

        for (auto& v : board) {
            for (auto& c : v) {
                if (c == 'T')
                    c = 'O';
            }
        }
    }
private:
    bool checkRegion(vector<vector<char>>& board, vector<pair<int, int>>& cells, int i, int j) {
        if (board[i][j] == 'X' || board[i][j] == 'T')
            return true;

        bool res = true;
        board[i][j] = 'T';
        cells.emplace_back(i, j);
        int crd[]{ 0,1,0,-1,0 };

        for (int c = 0; c < 4; ++c) {
            int ic = i + crd[c];
            int jc = j + crd[c + 1];

            if (ic < 0 || ic >= board.size() || jc < 0 || jc >= board.front().size()) {
                res = false;
                continue;
            }

            res = checkRegion(board, cells, ic, jc) && res;
        }

        return res;
    }
};

int main() {
    INIT_TIME(timer);

    vector<vector<char>> board{{'X','X','O','X'},{'O','O','O','X'},{'X','X','O','X'},{'X','O','X','O'}};

    PRINT_ELAPSED(timer);
    return 0;
}
