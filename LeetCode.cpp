// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        const int rows = board.size();
        const int cols = board.front().size();

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == '#') { continue; }

                if ((col == 0 || board[row][col - 1] == '#') && canPlaceWord(board, word, row, col, 0, 1)) { return true; }
                if ((col == cols - 1 || board[row][col + 1] == '#') && canPlaceWord(board, word, row, col, 0, -1)) { return true; }
                if ((row == 0 || board[row - 1][col] == '#') && canPlaceWord(board, word, row, col, 1, 0)) { return true; }
                if ((row == rows - 1 || board[row + 1][col] == '#') && canPlaceWord(board, word, row, col, -1, 0)) { return true; }
            }
        }

        return false;
    }
private:
    bool canPlaceWord(const vector<vector<char>>& board, const string& word, int row, int col, int rowChange, int colChange) {
        const int rows = board.size();
        const int cols = board.front().size();

        for (char c : word) {
            if (row < 0 || row == rows || col < 0 || col == cols) { return false; }
            if (board[row][col] != c && board[row][col] != ' ') { return false; }

            row += rowChange;
            col += colChange;
        }

        return row == rows || row == -1 || col == cols || col == -1 || board[row][col] == '#';
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}