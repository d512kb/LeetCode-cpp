// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int sum = 0;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i - 1] < prices[i]) {
                sum += prices[i] - prices[i - 1];
            } else {
                profit += sum;
                sum = 0;
            }
        }

        return profit + sum;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << endl;

    PRINT_ELAPSED(timer);
    return 0;
}
