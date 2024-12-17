// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int rollsSum = accumulate(rolls.begin(), rolls.end(), 0);
        int targetSum = (rolls.size() + n) * mean - rollsSum;

        if (targetSum < n || targetSum > 6 * n) { return {}; }

        vector<int> result(n, targetSum / n);
        fill_n(result.begin(), targetSum % n, 1 + (targetSum / n));

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}