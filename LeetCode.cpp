// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> gainData;

        int sz = profits.size();
        for (int i = 0; i < sz; ++i) {
            gainData.emplace_back(capital[i], profits[i]);
        }

        sort(gainData.begin(), gainData.end());

        priority_queue<int> gains;
        int i = 0;

        while (k--) {
            for (; i < sz && gainData[i].first <= w; ++i) {
                gains.push(gainData[i].second);
            }

            if (gains.empty())
                return w;

            w += gains.top();
            gains.pop();
        }

        return w;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
