// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int word1chars[26];
        int word2chars[26];
        memset(word1chars, 0, sizeof(word1chars));
        memset(word2chars, 0, sizeof(word2chars));

        if (word1.size() != word2.size()) {
            return false;
        }

        for (int i = 0, sz = word1.size(); i < sz; ++i) {
            ++word1chars[word1[i] - 'a'];
            ++word2chars[word2[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            int fromCount = word1chars[i];
            int toCount = word2chars[i];

            if (toCount != fromCount) {
                if (toCount == 0 || fromCount == 0) {
                    return false;
                }

                auto iter = find(word1chars + i + 1, end(word1chars), toCount);
                if (iter == end(word1chars)) {
                    return false;
                }

                *iter = fromCount;
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