// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int a = 0;
        int b = 0;
        vector<vector<int>> result;

        while (b < s.size()) {
            if (s[a] == s[b]) {
                ++b;
            }
            else {
                if (b - a >= 3) {
                    result.push_back({ a, b - 1 });
                }

                a = b;
            }
        }

        if (b - a >= 3) {
            result.push_back({ a, b - 1 });
        }

        sort(result.begin(), result.end());

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}