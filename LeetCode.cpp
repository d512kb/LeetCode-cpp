// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        auto endIter = words.find(endWord);
        if (endIter == words.end())
            return 0;

        queue<string> q;
        q.push(beginWord);
        int wordCount{ 1 };

        while (!q.empty()) {
            ++wordCount;
            int i = q.size();

            for (; i > 0; --i) {
                string word(move(q.front()));
                int wordSize = word.size();
                q.pop();

                for (int w = 0; w < wordSize; ++w) {
                    char prevC = word[w];

                    for (int c = 'a'; c <= 'z'; ++c) {
                        word[w] = c;

                        auto iter = words.find(word);
                        if (iter != words.end()) {
                            if (iter == endIter)
                                return wordCount;

                            q.push(words.extract(iter).value());
                            words.erase(iter);
                        }
                    }

                    word[w] = prevC;
                }
            }
        }

        return 0;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
