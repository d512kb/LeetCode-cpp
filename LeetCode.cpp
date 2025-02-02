// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int16_t> positions(1001, 1000);

        for (int i = 0; i < arr2.size(); ++i) { positions[arr2[i]] = i; }

        auto cmp = [&positions](int a, int b) {
            if (positions[a] == positions[b]) { return a < b; }

            return positions[a] < positions[b];
        };

        sort(arr1.begin(), arr1.end(), cmp);

        return arr1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}