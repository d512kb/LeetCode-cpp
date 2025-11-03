// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) { return false; }

        int left = 0;
        int right = arr.size() - 1;

        while (left < arr.size() - 2 && arr[left] < arr[left + 1]) {
            ++left;
        }

        while (right > 1 && arr[right - 1] > arr[right]) {
            --right;
        }

        return left == right;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}