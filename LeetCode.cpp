// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels{ 'a','A','e','E','i','I','o','O','u','U' };

        auto leftIndex = find_first_of(s.begin(), s.end(), vowels.begin(), vowels.end());
        auto rightIndex = find_first_of(s.rbegin(), s.rend(), vowels.begin(), vowels.end());

        while (leftIndex < rightIndex.base()) {
            iter_swap(leftIndex, rightIndex);

            leftIndex = find_first_of(leftIndex + 1, s.end(), vowels.begin(), vowels.end());
            rightIndex = find_first_of(rightIndex + 1, s.rend(), vowels.begin(), vowels.end());
        }

        return s;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}