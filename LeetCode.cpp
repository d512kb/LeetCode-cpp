// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board.front().size(); ++c) {
                if (exist(board, r, c, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool exist(vector<vector<char>>& board, int r, int c, const string& word, int index) {
        if (index == word.size()) {
            return true;
        }

        if (r < 0 || r >= board.size() || c < 0 || c >= board.front().size() || word[index] != board[r][c]) {
            return false;
        }

        char ch = board[r][c];
        board[r][c] = 0;
        ++index;

        bool result = exist(board, r + 1, c, word, index)
            || exist(board, r - 1, c, word, index)
            || exist(board, r, c + 1, word, index)
            || exist(board, r, c - 1, word, index);

        board[r][c] = ch;

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
