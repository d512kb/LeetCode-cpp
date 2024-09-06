// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpSums;
        int acc = 0;
        for (int& n : nums) {
            n += acc;
            ++mpSums[n];
            acc = n;
        }

        int result = 0;
        int corr = 0;
        for (int n : nums) {
            result += mpSums[corr + k];
            --mpSums[n];
            corr = n;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}