// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const int sz = arr.size();
        arr[0] = 1;

        for (int i = 1; i < sz; ++i) {
            arr[i] = min(arr[i - 1] + 1, arr[i]);
        }

        return arr[sz - 1];
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}