// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> v;

        calculate(result, v, 1, n, k);

        return result;
    }
private:
    void calculate(vector<vector<int>>& result, vector<int>& v, int a, int n, int k) {
        if (v.size() == k) {
            result.push_back(v);
            return;
        }

        for (a; a <= n; ++a) {
            v.push_back(a);
            calculate(result, v, a + 1, n, k);
            v.pop_back();
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
