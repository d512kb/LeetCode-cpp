// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class StockPrice {
    using PriceIterator = multiset<int>::iterator;
public:
    StockPrice() : m_latestTimestamp(0) {

    }

    void update(int timestamp, int price) {
        auto updateStatus = m_timeToPrice.emplace(timestamp, PriceIterator{});

        if (!updateStatus.second) { m_prices.erase(updateStatus.first->second); }
        updateStatus.first->second = m_prices.insert(price);

        if (timestamp > m_latestTimestamp) { m_latestTimestamp = timestamp; }
    }

    int current() {
        return *m_timeToPrice[m_latestTimestamp];
    }

    int maximum() {
        return *m_prices.rbegin();
    }

    int minimum() {
        return *m_prices.begin();
    }
private:
    unordered_map<int, PriceIterator> m_timeToPrice;
    multiset<int> m_prices;
    int m_latestTimestamp;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}