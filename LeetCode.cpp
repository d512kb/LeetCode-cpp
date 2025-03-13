// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;

        for (int width = 2; width < 10; ++width) {
            int num = 0;
            int inc = 0;

            for (int s = 1; s <= width; ++s) {
                num = num * 10 + s;
                inc = inc * 10 + 1;
            }

            while (num <= high && num % 10 != 0) {
                if (num >= low) { result.push_back(num); }

                num += inc;
            }

        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}