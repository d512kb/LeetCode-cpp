// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x <= y) { return y - x; }

        queue<int> q({ x });
        unordered_set<int> triedNumbers;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                x = q.front();
                q.pop();

                if (!triedNumbers.insert(x).second) { continue; }

                if (x == y) { return steps; }
                if (x < y) { q.push(x + 1); continue; }
                if (x % 11 == 0) { q.push(x / 11); }
                if (x % 5 == 0) { q.push(x / 5); }
                q.push(x - 1);
                q.push(x + 1);
            }

            ++steps;
        }

        return steps;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}