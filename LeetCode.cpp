// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int D = sqrt(1 + 8 * grades.size()); // quadratic equation x*x + x == 2*n, where x is group size
        return (-1 + D) / 2;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}