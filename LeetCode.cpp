// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz = nums.size();
        return (sz * (sz + 1) / 2) - accumulate(begin(nums), end(nums), 0);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}