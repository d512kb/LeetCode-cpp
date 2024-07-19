// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> st;
        st.reserve(temperatures.size());
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            int t = temperatures[i];

            while (!st.empty() && temperatures[st.back()] < t) {
                result[st.back()] = i - st.back();
                st.pop_back();
            }

            st.push_back(i);
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}