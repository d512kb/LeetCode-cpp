// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> data;

        for (int n : nums) {
            auto iter = lower_bound(data.begin(), data.end(), n);

            if (iter == data.end()) {
                data.push_back(n);
            } else {
                *iter = n;
            }
        }

        return data.size();
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
