// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] == e2[0] ? e1[1] > e2[1] : e1[0] < e2[0];
        });
        vector<int> lis;

        for (auto& e : envelopes) {
            int height = e[1];
            auto iter = lower_bound(lis.begin(), lis.end(), height);

            if (iter == lis.end()) {
                lis.push_back(height);
            } else {
                *iter = height;
            }
        }

        return lis.size();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}