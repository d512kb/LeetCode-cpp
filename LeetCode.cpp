// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int val = *max_element(candies.begin(), candies.end()) - extraCandies;

        vector<bool> result(candies.size());
        transform(candies.begin(), candies.end(), result.begin(), [val](int c) { return c >= val; });

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}