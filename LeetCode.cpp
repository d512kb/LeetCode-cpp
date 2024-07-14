// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        auto hBegin = horizontalCut.begin();
        auto hEnd = horizontalCut.end();
        auto vBegin = verticalCut.begin();
        auto vEnd = verticalCut.end();

        sort(hBegin, hEnd, greater<int>());
        sort(vBegin, vEnd, greater<int>());

        int horizontalCost = accumulate(hBegin, hEnd, 0);
        int verticalCost = accumulate(vBegin, vEnd, 0);

        int totalCost = 0;

        while (hBegin < hEnd && vBegin < vEnd) {
            if (*hBegin > *vBegin) {
                totalCost += *hBegin + verticalCost;
                horizontalCost -= *hBegin;
                ++hBegin;
            } else {
                totalCost += *vBegin + horizontalCost;
                verticalCost -= *vBegin;
                ++vBegin;
            }
        }

        totalCost += horizontalCost + verticalCost;

        return totalCost;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}