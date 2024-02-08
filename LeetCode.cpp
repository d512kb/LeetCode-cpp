// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int maxSum = 0;

        for (int i = 1; i < prices.size(); ++i) {
            sum += prices[i] - prices[i - 1];

            if (sum < 0) {
                sum = 0;
            } else if (sum > maxSum) {
                maxSum = sum;
            }
        }

        return maxSum;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << endl;

    PRINT_ELAPSED(timer);
    return 0;
}
