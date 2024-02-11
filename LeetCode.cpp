// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int path = 0;
        int max = -1;
        int index = -1;

        for (int i = gas.size() - 1; i >= 0; --i) {
            path += gas[i] - cost[i];
            if (path > max) {
                max = path;
                index = i;
            }
        }

        return path < 0 ? -1 : index;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
