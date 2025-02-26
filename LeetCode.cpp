// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2) { return {}; }

        vector<long long> result;
        int subtract = 2;

        while (finalSum >= subtract) {
            result.push_back(subtract);
            finalSum -= subtract;
            subtract += 2;
        }

        result.back() += finalSum;

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}