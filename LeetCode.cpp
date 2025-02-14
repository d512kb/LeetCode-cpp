// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        unordered_set<int> checked;

        auto pourWater = [&](auto&& self, int xJug, int yJug) -> bool {
            if (!checked.insert((xJug << 10) + yJug).second) { return false; }
            if (xJug == target || yJug == target || xJug + yJug == target) { return true; }

            int smallToLarge = min(xJug, y - yJug);
            int largeToSmall = min(yJug, x - xJug);

            return self(self, x, yJug) || self(self, xJug, y) ||
                self(self, 0, yJug) || self(self, xJug, 0) ||
                self(self, xJug - smallToLarge, yJug + smallToLarge) ||
                self(self, xJug + largeToSmall, yJug - largeToSmall);
        };

        return pourWater(pourWater, 0, 0);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}