// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<char> digits;

        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }

        auto iter = is_sorted_until(digits.begin(), digits.end());
        if (iter == digits.end()) { return -1; }

        iter_swap(iter, upper_bound(digits.begin(), iter, *iter));
        reverse(digits.begin(), iter);

        constexpr int maxMult = numeric_limits<int>::max() / 10;
        int test = 0;
        for (int k = digits.size() - 1; k >= 0; --k) {
            if (test > maxMult) { return -1; }
            test *= 10;
            if (test > numeric_limits<int>::max() - digits[k]) { return -1; }
            test += digits[k];
        }

        return test;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}