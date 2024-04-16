// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix.front().front() || target > matrix.back().back())
            return false;

        int a = 0;
        int b = matrix.size() - 1;
        int mid = 0;

        while (a <= b) {
            mid = (a + b) / 2;
            int lval = matrix[mid].front();
            int rval = matrix[mid].back();

            if (target < lval) {
                b = mid - 1;
            } else if (rval < target) {
                a = mid + 1;
            } else {
                break;
            }
        }

        vector<int>& row = matrix[mid];

        a = 0;
        b = row.size() - 1;

        while (a <= b) {
            mid = (a + b) / 2;
            int val = row[mid];

            if (target < val) {
                b = mid - 1;
            } else if (val < target) {
                a = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
