// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        for (const auto& c : click) {
            int row = click[0];
            int col = click[1];

            if (board[row][col] == 'M') {
                board[row][col] = 'X';
                break;
            }

            reveal(board, row, col);
        }

        return board;
    }
private:
    void reveal(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row == board.size() || col < 0 || col == board.front().size()) { return; }
        char& currCell = board[row][col];
        if (currCell == 'B' || (currCell >= '1' && currCell <= '8')) { return; }

        int minesAround = countMinesAround(board, row, col);

        if (minesAround) {
            currCell = '0' + minesAround;
        } else {
            currCell = 'B';

            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    if (i == 0 && j == 0) { continue; }

                    reveal(board, row + i, col + j);
                }
            }
        }
    }

    int countMinesAround(const vector<vector<char>>& board, int row, int col) {
        int result = 0;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int newRow = row + i;
                int newCol = col + j;

                if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board.front().size()) {
                    result += board[newRow][newCol] == 'M';
                }
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