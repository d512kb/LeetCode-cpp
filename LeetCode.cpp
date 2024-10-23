// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    unordered_map<int, int> divisors;
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int nextVal = nums.back();

        for (int i = nums.size() - 2; i >= 0; --i) {
            int& n = nums[i];

            while (n > nextVal) {
                int div = getDivisor(n);
                if (div == n) { return -1; }

                n /= div;
                ++ans;
            }

            nextVal = n;
        }

        return ans;
    }
private:
    int getDivisor(int n) {
        if (divisors[n] == 0) {
            divisors[n] = n;

            for (int i = n / 2; i > 1; --i) {
                if (n % i == 0) {
                    divisors[n] = i;
                    return i;
                }
            }
        }

        return divisors[n];
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}