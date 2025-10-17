// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> cachedFriends(friends.begin(), friends.end());
        vector<int> result;

        for (int o : order) {
            if (cachedFriends.contains(o)) {
                result.push_back(o);
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