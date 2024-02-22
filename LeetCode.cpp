// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordsNumber;
        int wordLen = words.front().size();
        int permLen = words.size() * wordLen;
        vector<int> result;

        if (s.size() < permLen)
            return result;

        for (const auto& word : words) {
            ++wordsNumber[word];
        }

        for (int baseIndex = 0; baseIndex < wordLen; ++baseIndex) {
            unordered_map<string, int> windowWordsNumber;
            queue<string> windowWords;
            int wordCount = 0;
            int startIndex = baseIndex;

            for (startIndex; startIndex < baseIndex + permLen; startIndex += wordLen) {
                string word = s.substr(startIndex, wordLen);
                auto iter = wordsNumber.find(word);

                if (iter != wordsNumber.end()) {
                    windowWords.push(word);

                    if (++windowWordsNumber[word] <= iter->second) {
                        ++wordCount;
                    }
                } else {
                    windowWords.emplace("");
                }

                if (wordCount == words.size()) {
                    result.push_back(startIndex - permLen + wordLen);
                }
            }

            for (startIndex; startIndex <= s.size() - wordLen; startIndex += wordLen) {
                string word = s.substr(startIndex, wordLen);
                auto iter = wordsNumber.find(word);

                if (iter != wordsNumber.end()) {
                    windowWords.push(word);

                    if (++windowWordsNumber[word] <= iter->second) {
                        ++wordCount;
                    }
                } else {
                    windowWords.emplace("");
                }

                if (!windowWords.front().empty()) {
                    if (--windowWordsNumber[windowWords.front()] < wordsNumber[windowWords.front()])
                        --wordCount;
                }

                windowWords.pop();

                if (wordCount == words.size()) {
                    result.push_back(startIndex - permLen + wordLen);
                }
            }
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
