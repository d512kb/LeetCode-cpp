// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;

        for (const auto& d : details) {
            if (stoi(d.substr(11, 2)) > 60) {
                ++ans;
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