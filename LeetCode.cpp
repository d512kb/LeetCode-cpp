// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k) { return false; }

        multiset<int> st(nums.begin(), nums.end());

        while (!st.empty()) {
            int min = st.extract(st.begin()).value();

            for (int i = 1; i < k; ++i) {
                if (!st.extract(++min)) { return false; }
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