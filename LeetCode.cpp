// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        st.push(-1);

        auto pushIter = pushed.begin();
        auto popIter = popped.begin();

        while (popIter != popped.end()) {
            while (st.top() != *popIter && pushIter != pushed.end()) {
                st.push(*pushIter++);
            }

            if (st.top() == *popIter) {
                st.pop();
                ++popIter;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}