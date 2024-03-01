// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int ind = 0;
        return calculateRecur(0, s, ind);
    }

private:
    int calculateRecur(int sum, const string& s, int& ind) {
        string num;
        bool minus = false;

        for (int i = ind; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                num.push_back(s[i]);
            } else if (s[i] == '(') {
                int b = calculateRecur(0, s, ++i);
                sum = minus ? sum - b : sum + b;
            } else if (s[i] == ')') {
                ind = i;
                break;
            } else if (s[i] == '-' || s[i] == '+') {
                if (!num.empty()) {
                    int b = stoi(num);
                    sum = minus ? sum - b : sum + b;
                    num.clear();
                }

                minus = s[i] == '-';
            }
        }

        if (!num.empty()) {
            int b = stoi(num);
            sum = minus ? sum - b : sum + b;
        }

        return sum;
    }
};

int main() {
    INIT_TIME(timer);

    Solution sol;
    sol.calculate("1-(-2)");
        
    PRINT_ELAPSED(timer);
    return 0;
}
