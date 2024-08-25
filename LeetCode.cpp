// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> result;
        result.reserve(spells.size());

        for (int64_t spell : spells) {
            int64_t reqPotion = ceil(static_cast<double>(success) / spell);

            result.push_back(distance(lower_bound(potions.begin(), potions.end(), reqPotion), potions.end()));
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}