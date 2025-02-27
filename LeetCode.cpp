// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> result(pref.size());
        result[0] = pref[0];

        for (int i = 1; i < pref.size(); ++i) {
            result[i] = pref[i] ^ pref[i - 1];
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