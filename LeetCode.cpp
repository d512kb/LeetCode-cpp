// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> h, v, z;

        for (int i = 0; i < 9; ++i) {
            h.assign(64, 0);
            v.assign(64, 0);
            z.assign(64, 0);

            for (int j = 0; j < 9; ++j) {
                char& hc = board[i][j];
                char& vc = board[j][i];
                char& zc = board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3];

                if (hc != 46 && ++h[hc] > 1) {
                    return false;
                } else if (vc != 46 && ++v[vc] > 1) {
                    return false;
                } else if (zc != 46 && ++z[zc] > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
