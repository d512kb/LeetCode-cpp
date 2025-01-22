// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> fbWords(forbidden.begin(), forbidden.end());

        int ans = 0;
        int validEnd = word.size();

        for (int i = word.size() - 1; i >= 0; --i) {
            string str;

            for (int j = i; j < validEnd && j - i < 10; ++j) {
                str.push_back(word[j]);

                if (fbWords.contains(str)) {
                    ans = max(ans, validEnd - i - 1); // we count all the chars between two forbidden words not including the first char
                    validEnd = j;
                    break;
                }
            }
        }

        return max(ans, validEnd);
    }
};

int main()
{
    INIT_TIME(timer);
    
    PRINT_ELAPSED(timer);
    return 0;
}