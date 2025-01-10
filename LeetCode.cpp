// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long appealSum(string s) {
        vector<int> lastPos(26, -1);
        int64_t ans = 0;
        int64_t appeal = 0;

        for (int i = 0; i < s.size(); ++i) {
            appeal += i - exchange(lastPos[s[i] - 'a'], i);
            ans += appeal;
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}