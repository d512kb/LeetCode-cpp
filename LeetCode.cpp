// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<short> occurrences(2001);
        unordered_set<int> usedOccurrences;

        for (int i : arr) {
            ++occurrences[i + 1000];
        }

        for (int oc : occurrences) {
            if (oc) {
                if (!usedOccurrences.insert(oc).second) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}