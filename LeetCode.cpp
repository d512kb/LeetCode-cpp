// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<size_t> possibleWords;
        for (const auto& word : startWords) { possibleWords.insert(calcHash(word)); }

        int result = 0;

        for (auto& word : targetWords) {
            auto wordHash = calcHash(word);

            for (char c : word) {
                wordHash &= ~(1 << (c - 'a'));

                if (possibleWords.contains(wordHash)) {
                    ++result;
                    break;
                }

                wordHash |= static_cast<size_t>(1) << (c - 'a');
            }
        }

        return result;
    }
private:
    size_t calcHash(const string& str) {
        size_t hash = 0;

        for (char c : str) {
            hash |= static_cast<size_t>(1) << (c - 'a');
        }

        return hash;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}