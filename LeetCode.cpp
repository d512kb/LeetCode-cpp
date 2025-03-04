// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowelsToSort;

        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                vowelsToSort.push_back(s[i]);
            }
        }

        sort(vowelsToSort.begin(), vowelsToSort.end());

        for (int i = 0, vi = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                s[i] = vowelsToSort[vi++];
            }
        }

        return s;
    }
private:
    bool isVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}