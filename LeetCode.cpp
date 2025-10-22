// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> transformations;
        array<string, 26> codes{ ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

        for (const auto& word : words) {
            string codedWord;

            for (char c : word) {
                codedWord += codes[c - 'a'];
            }

            transformations.insert(codedWord);
        }

        return transformations.size();
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}