// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    Solution(vector<int>& w) : m_weights(w.size()) {
        transform(w.begin(), w.end(), m_weights.begin(), [acc = 0](int w) mutable {
            acc += w;
            return acc;
        });

        m_eng = mt19937(random_device{}());
        m_dist = uniform_int_distribution(1, m_weights.back());
    }

    int pickIndex() {
        int w = m_dist(m_eng);

        int a = 0;
        int b = m_weights.size() - 1;

        while (a <= b) {
            int mid = (a + b) / 2;
            int val = m_weights[mid];

            if (val < w) {
                a = mid + 1;
            } else if (val > w) {
                b = mid - 1;
            } else {
                return mid;
            }
        }

        return a;
    }
private:
    mt19937 m_eng;
    uniform_int_distribution<int> m_dist;
    vector<int> m_weights;
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}