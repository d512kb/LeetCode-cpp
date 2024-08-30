// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    array<bitset<10>, 9> h, v, s;

public:
    void solveSudoku(vector<vector<char>>& board) {
        prepareData(board);
        solve(board, 0, 0);
    }

private:
    bool solve(vector<vector<char>>& board, int row, int col) {
        if (col == 9) {
            return solve(board, row + 1, 0);
        }

        if (row == 9) {
            return true;
        }

        if (board[row][col] != '.') {
            return solve(board, row, col + 1);
        }

        for (int n = 1; n <= 9; ++n) {
            if (setNumber(board, row, col, n)) {
                if (solve(board, row, col + 1)) {
                    return true;
                }

                resetNumber(board, row, col, n);
            }
        }

        return false;
    }

    void prepareData(vector<vector<char>>& board) {
        for_each(h.begin(), h.end(), [](auto& bitset) { bitset.reset(); });
        for_each(v.begin(), v.end(), [](auto& bitset) { bitset.reset(); });
        for_each(s.begin(), s.end(), [](auto& bitset) { bitset.reset(); });

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    continue;
                }

                char num = board[row][col] - '0';

                h[row][num] = 1;
                v[col][num] = 1;
                s[getSquareIndex(row, col)][num] = 1;
            }
        }
    }

    inline char getSquareIndex(int row, int col) {
        return row / 3 * 3 + col / 3;
    }

    inline bool setNumber(vector<vector<char>>& board, int row, int col, int num) {
        if (h[row][num] || v[col][num] || s[getSquareIndex(row, col)][num]) {
            return false;
        }

        board[row][col] = num + '0';
        h[row][num] = 1;
        v[col][num] = 1;
        s[getSquareIndex(row, col)][num] = 1;

        return true;
    }

    inline void resetNumber(vector<vector<char>>& board, int row, int col, int num) {
        board[row][col] = '.';
        h[row][num] = 0;
        v[col][num] = 0;
        s[getSquareIndex(row, col)][num] = 0;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}