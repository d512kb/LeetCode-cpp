// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (char c : s) {
            if (st.empty()) { st.push(c); continue; }
            if (st.top() == 'A' && c == 'B') { st.pop(); continue; }
            if (st.top() == 'C' && c == 'D') { st.pop(); continue; }
            st.push(c);
        }

        return st.size();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}