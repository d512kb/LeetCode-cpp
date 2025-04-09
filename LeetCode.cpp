// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> result;

        for (int i = 0; i < variables.size(); ++i) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];

            if (calcPow(calcPow(a, b, 10), c, m) == target) {
                result.push_back(i);
            }
        }

        return result;
    }

private:
    int calcPow(int n, int p, int m) {
        int ans = 1;

        while (p-- > 0) {
            ans = (ans * n) % m;
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