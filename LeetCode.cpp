// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<char> nodes(n, 1);

        for (auto& e : edges) { nodes[e[1]] = 0; }

        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (nodes[i] == 1) result.push_back(i);
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}