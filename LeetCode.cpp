// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int sum = 0;
        int sign = 1;
        vector<pair<int, int>> sums;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '(') {
                sums.emplace_back(sum, sign);
                sign = 1;
                sum = 0;
            } else if (s[i] == ')') {
                sum = sum + sign * num;
                num = 0;

                sum = sums.back().first + sums.back().second * sum;
                sums.pop_back();
            } else if (s[i] == '-' || s[i] == '+') {
                sum += sign * num;
                num = 0;

                sign = ',' - s[i];
            }
        }

        sum += sign * num;

        return sum;
    }
};

int main() {
    INIT_TIME(timer);

    Solution sol;
    sol.calculate("1 - ((2 - 3) - (4 - 5))");
        
    PRINT_ELAPSED(timer);
    return 0;
}
