// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    Solution() {
        m_calculatedValues.reserve(1000);

        precalc();
    }

    int numTilings(int n) {
        return calc(n);
    }

private:
    void precalc() {
        m_calculatedValues.push_back(1); // zero value, filler
        m_calculatedValues.push_back(1); // value for n == 1;
        m_calculatedValues.push_back(2); // value for n == 2;
        m_calculatedValues.push_back(5); // value for n == 3;
    }

    int calc(int n) {
        int lastN = m_calculatedValues.size() - 1;

        while (lastN++ < n) {
            int64_t nextNVal = 2 * m_calculatedValues[lastN - 1] - m_calculatedValues[lastN - 2] + 2;
            nextNVal %= m_modulo;

            // calculate complements
            int complementIndex;
            for (complementIndex = 0; complementIndex < lastN - 4; ++complementIndex) {
                nextNVal += 4 * (lastN - (complementIndex + 4)) * static_cast<int64_t>(m_calculatedValues[complementIndex]);
                nextNVal %= m_modulo;
            }

            nextNVal += m_calculatedValues[complementIndex];
            nextNVal %= m_modulo;
            
            m_calculatedValues.push_back(nextNVal);
        }

        return m_calculatedValues[n];
    }

private:
    vector<int> m_calculatedValues;
    const int m_modulo = 1000000007;
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    cout << sol.numTilings(8) << endl;

    PRINT_ELAPSED(timer);
    return 0;
}
