// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int sz = piles.size();

        if (sz % 2 == 0) { return true; }

        for (int i = 0; i < sz; ++i) {
            array<int, 2> stones{ piles[1], 0 };
            char bobTurn = 1;
            int left = i - 1; int right = i + 1;

            while (left > 0 || right < sz - 1) {
                int leftVal = left - 1 >= 0 ? piles[left - 1] : 0;
                int rightVal = right + 1 < sz ? piles[right + 1] : 0;

                if (left > right) {
                    stones[bobTurn] += piles[left];
                    --left;
                } else {
                    stones[bobTurn] += piles[right];
                    ++right;
                }

                bobTurn = (bobTurn + 1) % 2;
            }

            if (stones[0] > stones[1]) { return true; }
        }

        return false;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}