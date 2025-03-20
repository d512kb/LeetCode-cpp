// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> monoStack({ prices.back() });

        for (int i = prices.size() - 2; i >= 0; --i) {
            while (!monoStack.empty() && monoStack.top() > prices[i]) {
                monoStack.pop();
            }

            if (monoStack.empty()) {
                monoStack.push(prices[i]);
            } else {
                int newPrice = prices[i] - monoStack.top();
                if (monoStack.top() != prices[i]) { monoStack.push(prices[i]); }
                prices[i] = newPrice;
            }
        }

        return prices;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}