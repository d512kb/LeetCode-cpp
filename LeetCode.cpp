// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        array<vector<pair<reference_wrapper<string>, int>>, 26> buckets;

        for (int i = 0; i < words.size(); ++i) {
            buckets[words[i].front() - 'a'].emplace_back(words[i], 0);
        }

        int result = 0;
        for (char c : s) {
            auto currentBuckets(std::move(buckets[c - 'a']));

            for (auto [word, wordCharIndex] : currentBuckets) {
                if (++wordCharIndex == word.get().size()) { ++result; } else {
                    buckets[word.get()[wordCharIndex] - 'a'].emplace_back(word, wordCharIndex);
                }
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}