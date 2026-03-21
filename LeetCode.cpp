// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        ans.reserve(num.size());

        int pos = num.size() - 1;
        for (; pos >= 0; --pos) {
            ans.push_back(k % 10 + num[pos]);
            k /= 10;

            if (ans.back() > 9) {
                ans.back() %= 10;
                k += 1;
            }
        }

        while (k) {
            ans.push_back(k % 10);
            k /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}