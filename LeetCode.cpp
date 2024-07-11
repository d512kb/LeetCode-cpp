// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentHeight = 0;
        int result = 0;

        for (int& i : gain) {
            currentHeight += i;
            result = max(result, currentHeight);
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}