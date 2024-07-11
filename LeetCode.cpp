// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result(word1.size() + word2.size(), 0);

        auto word1Iter = word1.begin();
        auto word2Iter = word2.begin();
        auto resultIter = result.begin();

        int n = min(word1.size(), word2.size());

        while (n--) {
            *resultIter++ = *word1Iter++;
            *resultIter++ = *word2Iter++;
        }

        while (word1Iter != word1.end()) {
            *resultIter++ = *word1Iter++;
        }

        while (word2Iter != word2.end()) {
            *resultIter++ = *word2Iter++;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}