// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        int i = 0;

        // skip all skippable leading zeroes
        while (i < num.size() && k > 0) {
            auto zeroPos = num.find('0', i);
            if (zeroPos - i > k) { break; }

            k -= zeroPos - i;
            i = num.find_first_not_of("0", zeroPos + 1);
        }

        // process the rest of the string
        for (i; i < num.size(); ++i) {
            while (!result.empty() && k > 0 && num[i] < result.back()) {
                result.pop_back();
                --k;
            }

            result.push_back(num[i]);
        }

        while (k > 0 && !result.empty()) {
            result.pop_back();
            --k;
        }

        return result.empty() ? "0" : result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}