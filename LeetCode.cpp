// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int16_t> cards(10001);

        for (int c : deck) { ++cards[c]; }
        cards.erase(remove(cards.begin(), cards.end(), 0), cards.end());

        int g = 0;

        for (int c : cards) {
            g = gcd(g, c);
        }

        return g > 1;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}