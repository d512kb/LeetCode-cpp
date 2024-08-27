// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        vector<int> st;

        for (char c : s) {
            if (c == '(') {
                st.push_back(0);
            } else {
                int sum = 0;
                while (!st.empty() && st.back() > 0) {
                    sum += st.back();
                    st.pop_back();
                }

                if (!st.empty()) {
                    sum += 2;
                    st.back() = sum;
                }

                ans = max(ans, sum);
            }
        }

        int sum = 0;
        for (int v : st) {
            sum += v;
            ans = max(ans, sum);

            if (v == 0) {
                sum = 0;
            }
        }

        return ans;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}