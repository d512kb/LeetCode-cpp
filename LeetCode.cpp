// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();

        for (int i = 1; i <= sz; ++i) {
            int& n = nums[i - 1];

            while (n != i && n > 0 && n <= sz && nums[n - 1] != n) {
                swap(n, nums[n - 1]);
            }
        }

        for (int i = 1; i <= sz; ++i) {
            if (nums[i - 1] != i) { return i; }
        }

        return sz + 1;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}