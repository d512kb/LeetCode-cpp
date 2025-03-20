// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int sz = code.size();
        if (k == 0) { return vector<int>(sz, 0); }

        int l = 0;
        int r = 0;
        if (k > 0) { l = 1; r = 1 + k; } else if (k < 0) { l = k; r = 0; }

        int sum = 0;

        for (int i = l; i < r; ++i) {
            sum += code[mod(i, sz)];
        }

        vector<int> result(sz);
        result[0] = sum;

        for (int i = 1; i < sz; ++i, ++l, ++r) {
            sum -= code[mod(l, sz)];
            sum += code[mod(r, sz)];
            result[i] = sum;
        }

        return result;
    }
private:
    inline int mod(int n, int k) {
        return (n %= k) < 0 ? n + k : n;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}