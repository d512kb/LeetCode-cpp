// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int neededEnergy = 0;
        int neededExperience = 0;

        for (int i = 0; i < energy.size(); ++i) {
            neededEnergy += energy[i];

            if (initialExperience <= experience[i]) {
                neededExperience += experience[i] - initialExperience + 1;
                initialExperience = experience[i] + 1;;
            }

            initialExperience += experience[i];
        }

        return max(0, neededEnergy + 1 - initialEnergy) + neededExperience;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}