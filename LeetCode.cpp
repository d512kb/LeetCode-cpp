// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int a = 0;
        int b = arr.size() - 1;

        while (a < b) {
            int mid = (a + b) / 2;

            if (arr[mid] < arr[mid + 1]) {
                a = mid + 1;
            } else {
                b = mid;
            }
        }

        return a;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}