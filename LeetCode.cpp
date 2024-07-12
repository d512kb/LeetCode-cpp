// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!n)
            return true;

        for (int i = 0, sz = flowerbed.size() - 1; i <= sz; ++i) {
            if (flowerbed[max(0, i - 1)] + flowerbed[i] + flowerbed[min(sz, i + 1)] == 0) {
                flowerbed[i] = 1;
                if (--n == 0)
                    return true;
            }
        }

        return false;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}