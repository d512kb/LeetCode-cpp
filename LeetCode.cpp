// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        m_cache.assign(prices.size(), vector<int>(2, -1));

        return calcPrices(prices, 0, true);
    }
private:
    int calcPrices(vector<int>& prices, int index, bool canBuy) {
        if (index >= prices.size()) {
            return 0;
        }

        int& result = m_cache[index][canBuy];

        if (result >= 0) {
            return result;
        }

        if (canBuy) {
            result = max(-prices[index] + calcPrices(prices, index + 1, false),
                         calcPrices(prices, index + 1, true));
        } else {
            result = max(prices[index] + calcPrices(prices, index + 2, true),
                         calcPrices(prices, index + 1, false));
        }

        return result;
    }

    vector<vector<int>> m_cache;
    int m_maxProfit;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}