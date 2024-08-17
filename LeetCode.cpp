// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int sz = isConnected.size();
        vector<char> visited(sz);
        int result = 0;

        for (int i = 0; i < sz; ++i) {
            if (!visited[i]) {
                vector<int> stack;
                stack.push_back(i);

                while (!stack.empty()) {
                    int city = stack.back();
                    visited[city] = 1;
                    stack.pop_back();

                    for (int c = 0; c < sz; ++c) {
                        if (!visited[c] && isConnected[city][c]) {
                            visited[c] = 1;
                            stack.push_back(c);
                        }
                    }
                }

                ++result;
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}