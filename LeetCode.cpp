// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);

        for (int i = 1; i <= n; ++i) {
            result[i] = i % 2 + result[i / 2];
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}