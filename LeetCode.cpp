// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        constexpr int yOffset = 1 + 1e4;
        constexpr int maxCoord = 2 * yOffset;
        const int sz = stones.size();
        vector<int> parent(maxCoord);
        vector<int> size(maxCoord, 0);
        iota(parent.begin(), parent.end(), 0);

        for (const auto& stone : stones) {
            join(parent, size, stone[0], stone[1] + yOffset);
        }

        int ans = 0;
        for (int s : size) {
            if (s > 1) {
                ans += s - 1;
            }
        }

        return ans;
    }
private:
    int find(vector<int>& parent, int id) {
        if (parent[id] == id) return id;
        return parent[id] = find(parent, parent[id]);
    }

    void join(vector<int>& parent, vector<int>& size, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);

        if (a == b) { ++size[a]; return; }
        if (size[a] > size[b]) {
            size[a] += exchange(size[b], 0) + 1;
            parent[b] = a;
        } else {
            size[b] += exchange(size[a], 0) + 1;
            parent[a] = b;
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}