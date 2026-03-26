// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int shift = count(arr.begin(), arr.end(), 0);
        const int end = arr.size() - 1;

        for (int i = end; i >= 0; --i) {
            if (arr[i] == 0) {
                if (i + shift <= end) { arr[i + shift] = 0; }
                --shift;
            }

            if (i + shift <= end) { arr[i + shift] = arr[i]; }
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}