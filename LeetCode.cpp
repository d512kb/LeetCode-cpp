// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class RangeModule {
public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        auto insertPos = m_ranges.lower_bound(left);

        if (insertPos != m_ranges.end()) {
            left = min(left, insertPos->second);
        }

        while (insertPos != m_ranges.end() && insertPos->first <= right) {
            insertPos = m_ranges.erase(insertPos);
        }

        if (insertPos != m_ranges.end() && insertPos->second <= right) {
            right = insertPos->first;
            m_ranges.erase(insertPos);
        }

        m_ranges[right] = left; // key is right, value is left
    }

    bool queryRange(int left, int right) {
        auto iter = m_ranges.lower_bound(right);

        if (iter == m_ranges.end()) { return false; }

        return iter->second <= left;
    }

    void removeRange(int left, int right) {
        auto erasePos = m_ranges.upper_bound(left);

        if (erasePos != m_ranges.end() && erasePos->second < left) {
            m_ranges.emplace(left, erasePos->second); // leave left cut
        }

        while (erasePos != m_ranges.end() && erasePos->first <= right) {
            erasePos = m_ranges.erase(erasePos);
        }

        if (erasePos != m_ranges.end() && erasePos->second < right) {
            erasePos->second = right;
        }
    }
private:
    map<int, int> m_ranges; // key is right, value is left
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}