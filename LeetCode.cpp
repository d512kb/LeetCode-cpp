// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int mx = 0;
        int64_t result = 0;

        for (int n : nums) {
            result += mx;
            if (n > mx) { mx = n; }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}