// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        const int sz = s.size();
        int ans = 0;

        for (int i = 0; i < sz; ++i) {
            int vowels = 0;
            int consonants = 0;

            for (int j = i; j < sz; ++j) {
                char c = s[j];

                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    ++vowels;
                } else {
                    ++consonants;
                }

                if (vowels == consonants && (vowels * consonants % k) == 0) {
                    ++ans;
                }
            }
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