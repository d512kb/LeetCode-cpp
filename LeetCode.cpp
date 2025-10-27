// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> wordsSet(words.begin(), words.end());
        int ans = 0;

        while (!wordsSet.empty()) {
            string word = *wordsSet.begin();
            reverse(word.begin(), word.end());

            auto iter = wordsSet.find(word);
            if (iter != wordsSet.begin() && iter != wordsSet.end()) {
                wordsSet.erase(iter);
                ++ans;
            }

            wordsSet.erase(wordsSet.begin());
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