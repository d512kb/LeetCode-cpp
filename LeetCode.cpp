// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int targetHIndex = citations.size();
        int hIndex = 0;

        for (int i = citations.size() - 1; i >= 0; --i, ++hIndex) {
            if (citations[i] <= targetHIndex) {
                if (hIndex < targetHIndex && hIndex < citations[i]) {
                    targetHIndex = citations[i];
                } else {
                    return hIndex;
                }
            }
        }

        return hIndex;
    }
};

int main() {
    Solution sol;

    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
