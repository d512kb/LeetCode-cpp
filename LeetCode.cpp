// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        int ans = 0;
        array<unordered_set<char>, 10> rods;

        for (int i = 0; i < rings.size(); i += 2) {
            rods[rings[i + 1] - '0'].insert(rings[i]);
        }

        return count_if(rods.begin(), rods.end(), [](const auto& rod) { return rod.size() == 3; });
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}