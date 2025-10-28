// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (count(suits.begin(), suits.end(), *suits.begin()) == 5) {
            return "Flush";
        }

        unordered_map<int, int> ranksSet;
        int maxRanks = 0;

        for (int r : ranks) {
            maxRanks = max(maxRanks, ++ranksSet[r]);
        }

        if (maxRanks >= 3) { return "Three of a Kind"; }
        if (maxRanks == 2) { return "Pair"; }

        return "High Card";
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}