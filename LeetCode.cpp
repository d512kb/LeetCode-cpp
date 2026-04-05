// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n / 2; ++i) {
            if (noZero(i) && noZero(n - i)) { return { i, n - i }; }
        }

        return {};
    }
private:
    bool noZero(int a) {
        while (a) {
            if (a % 10 == 0) { return false; }
            a /= 10;
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}