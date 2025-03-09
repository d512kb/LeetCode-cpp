// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int sz = 1;
        while (sz < baskets.size()) { sz *= 2; }

        vector<int> segmentTree(2 * sz);
        copy(baskets.begin(), baskets.end(), segmentTree.begin() + sz);
        for (int i = sz - 1; i > 0; --i) { segmentTree[i] = max(segmentTree[2 * i], segmentTree[2 * i + 1]); }

        int ans = 0;
        for (int f : fruits) {
            if (segmentTree[1] < f) {
                ++ans;
                continue;
            }

            int index = 1;
            while (index < sz) {
                if (segmentTree[2 * index] >= f) { index *= 2; } else { index = 2 * index + 1; }
            }

            segmentTree[index] = 0;

            while (index > 1) {
                index /= 2;
                int newVal = max(segmentTree[2 * index], segmentTree[2 * index + 1]);

                if (newVal != segmentTree[index]) { segmentTree[index] = newVal; } else { break; }
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