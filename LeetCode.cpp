// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int can = capacity;
        int ans = 0;

        for (int i = 0; i < plants.size(); ++i) {
            if (can < plants[i]) {
                ans += 2 * i;
                can = capacity;
            }

            can -= plants[i];
            ++ans;
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}