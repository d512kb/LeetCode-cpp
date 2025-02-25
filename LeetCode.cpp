// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        regex reg("\\w+");
        sregex_iterator regIter(paragraph.begin(), paragraph.end(), reg);
        auto endIter = sregex_iterator();
        unordered_map<string, int> wordCount;

        for (; regIter != endIter; ++regIter) {
            const string& sourceStr = regIter->str();
            string lowered;
            transform(sourceStr.begin(), sourceStr.end(), back_inserter(lowered), [](char c) { return tolower(c); });

            ++wordCount[lowered];
        }

        unordered_set<string> bannedWords(banned.begin(), banned.end());

        string result;
        int maxCount = 0;

        for (const auto& [word, count] : wordCount) {
            if (!bannedWords.contains(word) && count > maxCount) {
                maxCount = count;
                result = word;
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