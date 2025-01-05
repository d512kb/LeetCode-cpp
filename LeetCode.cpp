// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int row = 0;
        int ans = 0;
        int leftPartFree = 0;
        int centralPartFree = 0;
        int rightPartFree = 0;

        for (auto& seat : reservedSeats) {
            int place = seat[1];

            if (seat[0] > row) {
                ans += max(leftPartFree + rightPartFree, centralPartFree);
                ans += 2 * (seat[0] - row - 1); // add empty rows
                row = seat[0];
                leftPartFree = centralPartFree = rightPartFree = 1;
            }

            if (place >= 2 && place <= 5) { leftPartFree = 0; }
            if (place >= 4 && place <= 7) { centralPartFree = 0; }
            if (place >= 6 && place <= 9) { rightPartFree = 0; }
        }

        ans += max(leftPartFree + rightPartFree, centralPartFree);
        ans += 2 * (n - row);

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}