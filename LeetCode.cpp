// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> powers(1001);

        // for higher numbers it't better to use recursion + map to avoid recomputations
        for (int i = 0; i <= 1000; ++i) {
            int p = 0;
            int val = i;

            while (val > 1) {
                ++p;

                if (val % 2) { val = val * 3 + 1; } else { val /= 2; }
            }

            powers[i] = p;
        }

        vector<int> values(hi - lo + 1);
        iota(values.begin(), values.end(), lo);

        auto cmp = [&powers](int a, int b) {
            if (powers[a] == powers[b]) { return a < b; }
            return powers[a] < powers[b];
        };

        nth_element(values.begin(), values.begin() + k - 1, values.end(), cmp);
        return values[k - 1];
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}