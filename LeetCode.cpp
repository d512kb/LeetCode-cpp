// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const string& word : words) {
            bool palindromic = true;

            for (int i = 0, j = word.size() - 1; i <= j; ++i, --j) {
                if (word[i] != word[j]) {
                    palindromic = false;
                    break;
                }
            }

            if (palindromic) {
                return word;
            }
        }

        return "";
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}