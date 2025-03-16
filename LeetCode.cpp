// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st({ 0 });

        for (char c : s) {
            if (st.top() == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }

        string result;

        while (st.size() > 1) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}