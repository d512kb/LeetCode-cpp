// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int result = 0;
        int vowelsCount = 0;

        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                ++vowelsCount;
            }
        }

        result = vowelsCount;

        for (int i = 0, sz = s.size(); k < sz; ++i, ++k) {
            if (isVowel(s[i])) {
                --vowelsCount;
            }

            if (isVowel(s[k])) {
                ++vowelsCount;
            }

            result = max(result, vowelsCount);
        }

        return result;
    }
private:
    inline bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}