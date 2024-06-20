// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int64_t> powerToDamage{ {-5,0},{-4,0},{-3,0},{-2,0},{-1,0} };

        for (int p : power) {
            powerToDamage[p] += p;
        }

        auto mapLookbackIter = powerToDamage.begin();
        auto mapEndIter = powerToDamage.end();

        for (auto mapIter = next(mapLookbackIter, 6); mapIter != mapEndIter; ++mapIter, ++mapLookbackIter) {
            int64_t newDamage = 0;

            for (auto iter = mapLookbackIter; iter != mapIter; ++iter) {
                if (mapIter->first - iter->first < 3) {
                    break;
                }

                newDamage = max(newDamage, iter->second);
            }

            mapIter->second += newDamage;
        }

        return max_element(powerToDamage.rbegin(), next(powerToDamage.rbegin(), 3), [](auto& p1, auto& p2) { return p1.second < p2.second; })->second;
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}