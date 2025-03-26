// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        const int sz = word.size();
        int ans = 0;

        for (int i = 1; i < sz;) {
            if (abs(word[i] - word[i - 1]) <= 1) {
                ++ans;
                i += 2;
            } else {
                ++i;
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