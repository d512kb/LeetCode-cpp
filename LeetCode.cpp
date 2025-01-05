// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        int goodNumber = pow(10, n - 1);

        auto generate = [&](auto&& self, int n) -> void {
            if (n >= goodNumber) { result.push_back(n); return; };

            for (int i = 0; i <= 9; ++i) {
                if (abs(n % 10 - i) == k) {
                    self(self, (n * 10) + i);
                }
            }
        };

        for (int i = 1; i <= 9; ++i) { generate(generate, i); }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}