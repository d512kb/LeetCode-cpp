// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;

        for (; left <= right; ++left) {
            int n = left;

            while (n) {
                int div = n % 10;

                if (div == 0 || left % div) { break; }
                n /= 10;
            }

            if (n == 0) {
                result.push_back(left);
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}