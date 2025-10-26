// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        auto it = min_element(tasks.begin(), tasks.end(), [](const auto& t1, const auto& t2) { return (t1[0] + t1[1]) < (t2[0] + t2[1]); });

        return (*it)[0] + (*it)[1];
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}