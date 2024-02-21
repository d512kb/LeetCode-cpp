// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordsNumber;
        unordered_map<string, int> wordsCount;

        for (const auto& word : words) {
            ++wordsNumber[word];
        }

        int wordSize = words.front().size();
        int permLen = words.size() * wordSize;
        int maxIndex = s.size() - permLen;
        vector<int> result;

        for (int i = 0; i <= maxIndex; ++i) {
            wordsCount = wordsNumber;
            int checkIndex = 0;

            while (checkIndex < permLen && --wordsCount[s.substr(i+checkIndex, wordSize)] >= 0) {
                checkIndex += wordSize;
            }

            if (checkIndex == permLen)
                result.push_back(i);
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
