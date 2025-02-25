// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> result;

        if (rounds.front() <= rounds.back()) {
            for (int i = rounds.front(); i <= rounds.back(); ++i) {
                result.push_back(i);
            }
        } else {
            for (int i = 1; i <= rounds.back(); ++i) { result.push_back(i); }
            for (int i = rounds.front(); i <= n; ++i) { result.push_back(i); }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}