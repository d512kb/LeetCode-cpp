// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        const int sz = words.size();
        vector<int> chainLengths(sz);

        sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.size() < b.size(); });

        auto calcLengths = [&](auto&& self, int wordIndex) {
            int& result = chainLengths[wordIndex];
            if (result > 0) { return result; }

            const auto& word = words[wordIndex];
            result = 1;

            for (int i = wordIndex + 1; i < sz; ++i) {
                const auto& nextWord = words[i];
                if (nextWord.size() == word.size()) { continue; }
                if (nextWord.size() - word.size() > 1) { break; }

                int ai = 0;
                int bi = 0;

                while (ai < word.size() && bi < nextWord.size()) {
                    if (word[ai] != nextWord[bi]) {
                        ++bi;
                    } else {
                        ++ai;
                        ++bi;
                    }
                }

                if (bi - ai <= 1) {
                    result = max(result, 1 + self(self, i));
                }
            }

            return result;
        };

        for (int i = 0; i < sz; ++i) {
            calcLengths(calcLengths, i);
        }

        return *max_element(chainLengths.begin(), chainLengths.end());
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}