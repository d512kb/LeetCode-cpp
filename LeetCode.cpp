// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'R') {
                    for (int c = j + 1; c < board[0].size(); ++c) {
                        if (board[i][c] != '.') {
                            ans += board[i][c] == 'p';
                            break;
                        }
                    }
                    for (int c = j - 1; c >= 0; --c) {
                        if (board[i][c] != '.') {
                            ans += board[i][c] == 'p';
                            break;
                        }
                    }
                    for (int r = i + 1; r < board.size(); ++r) {
                        if (board[r][j] != '.') {
                            ans += board[r][j] == 'p';
                            break;
                        }
                    }
                    for (int r = i - 1; r >= 0; --r) {
                        if (board[r][j] != '.') {
                            ans += board[r][j] == 'p';
                            break;
                        }
                    }

                    return ans;
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