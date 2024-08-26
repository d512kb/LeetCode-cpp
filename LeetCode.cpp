// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class StockSpanner {
public:
    StockSpanner() {
        m_stocks.reserve(10000);
    }

    int next(int price) {
        int span = 1;

        while (!m_stocks.empty() && m_stocks.back().first <= price) {
            span += m_stocks.back().second;
            m_stocks.pop_back();
        }

        m_stocks.emplace_back(price, span);
        return span;
    }
private:
    vector<pair<int, int>> m_stocks;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}