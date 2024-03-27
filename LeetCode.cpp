// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int n2 = n * n;

        vector<int> linear(n2 + 1);

        int i = 1;
        for (int line = n - 1; line > 0; line -= 2) {
            for (int item : board[line]) {
                linear[i++] = item;
            }

            auto a = board[line - 1].rbegin();
            auto b = board[line - 1].rend();
            for (a; a < b; ++a) {
                linear[i++] = *a;
            }
        }

        if (n % 2) {
            for (int item : board[0]) {
                linear[i++] = item;
            }
        }

        queue<int> q;
        q.push(1);
        linear[1] = 0;
        int stepCount = 0;

        while (!q.empty()) {
            int s = q.size();
            ++stepCount;

            for (; s > 0; --s) {
                int a = q.front();
                q.pop();

                for (int next = 1; next <= 6; ++next) {
                    if (a + next == n2 || linear[a + next] == n2)
                        return stepCount;

                    if (linear[a + next])
                        q.push(linear[a + next] == -1 ? a + next : linear[a + next]);

                    linear[a + next] = 0;
                }
            }
        }

        return -1;
    }
};

int main() {
    INIT_TIME(timer);

    vector<vector<int>> v {{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};

    Solution sol;
    int i = sol.snakesAndLadders(v);

    PRINT_ELAPSED(timer);
    return 0;
}
