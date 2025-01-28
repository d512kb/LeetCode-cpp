// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wSet(words.begin(), words.end());
        vector<string> result;

        for (const auto& word : words) {
            vector<char> dp(word.size() + 1);
            dp[0] = 1;

            for (int i = 0; i < word.size(); ++i) {
                if (!dp[i]) { continue; }

                string str;
                for (int j = i; j < word.size(); ++j) {
                    str.push_back(word[j]);

                    if (wSet.contains(str)) { ++dp[j + 1]; }
                }
            }

            if (dp.back() > 1) { result.push_back(word); }
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