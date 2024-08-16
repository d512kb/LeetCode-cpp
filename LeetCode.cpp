// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int removeRadiant = 0;
        int removeDire = 0;
        bool voted = true;
        char lastVoter = 0;

        while (voted) {
            voted = false;

            for (char& c : senate) {
                if (c == 'R') {
                    if (removeRadiant > 0) {
                        c = 'r';
                        --removeRadiant;
                        voted = true;
                    } else {
                        lastVoter = c;
                        ++removeDire;
                    }
                } else if (c == 'D') {
                    if (removeDire > 0) {
                        c = 'd';
                        --removeDire;
                        voted = true;
                    } else {
                        lastVoter = c;
                        ++removeRadiant;
                    }
                }
            }
        }

        return lastVoter == 'R' ? "Radiant" : "Dire";
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}