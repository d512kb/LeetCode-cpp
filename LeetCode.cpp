// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddsCount = 0;

        for (int n : arr) {
            if (n % 2) {
                if (++oddsCount == 3)
                    return true;
            } else {
                oddsCount = 0;
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