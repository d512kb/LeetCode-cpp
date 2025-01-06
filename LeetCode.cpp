// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        if (n % 2) { --n; }

        for (int i = 1; i < n; i += 2) {
            result[i] = i;
            result[i - 1] = -i;
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