// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        const int sz = tops.size();
        array<int, 7> top{}, bottom{}, both{};

        for (int i = 0; i < sz; ++i) {
            if (tops[i] != bottoms[i]) {
                ++top[tops[i]];
                ++bottom[bottoms[i]];
            } else {
                ++both[tops[i]];
            }
        }

        for (int i = 1; i <= 6; ++i) {
            if (top[i] + bottom[i] == sz - both[i]) { return min(top[i], bottom[i]); }
        }

        return -1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}