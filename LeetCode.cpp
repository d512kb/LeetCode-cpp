// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class ATM {
    static constexpr char s_banknotesCount = 5;
public:
    ATM() : m_cash(s_banknotesCount), m_banknotes{ 20, 50, 100, 200, 500 } {

    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < s_banknotesCount; ++i) {
            m_cash[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> withdrewCash(5);

        for (int i = s_banknotesCount - 1; i >= 0 && amount > 0; --i) {
            withdrewCash[i] += min(m_cash[i], amount / m_banknotes[i]);
            amount -= withdrewCash[i] * m_banknotes[i];
        }

        if (amount) { return { -1 }; }

        for (int i = 0; i < s_banknotesCount; ++i) {
            m_cash[i] -= withdrewCash[i];
        }

        return withdrewCash;
    }
private:
    vector<int> m_cash;
    array<int, s_banknotesCount> m_banknotes;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}