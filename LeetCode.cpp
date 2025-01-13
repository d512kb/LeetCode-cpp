// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumBuckets(string hamsters) {
        int ans = 0;
        const int sz = hamsters.size();

        for (int i = 0; i < sz; ++i) {
            if (hamsters[i] == 'H') {
                if (i > 0 && hamsters[i - 1] == 'o') { continue; }
                if (i < sz - 1 && hamsters[i + 1] == '.') { hamsters[i + 1] = 'o'; ++ans; continue; }
                if (i > 0 && hamsters[i - 1] == '.') { hamsters[i - 1] = 'o'; ++ans; continue; }
                return -1;
            }
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