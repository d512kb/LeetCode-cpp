// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int a = 0;
        int b = arr.size() - 1;

        while (b - a >= k) {
            if (abs(arr[a] - x) > abs(arr[b] - x)) {
                ++a;
            } else {
                --b;
            }
        }

        return vector<int>(arr.begin() + a, arr.begin() + b + 1);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}