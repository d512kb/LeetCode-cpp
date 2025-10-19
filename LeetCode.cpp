// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        auto longestSent = max_element(sentences.begin(), sentences.end(), [](const auto& sent1, const auto& sent2) {
            return count(sent1.begin(), sent1.end(), ' ') < count(sent2.begin(), sent2.end(), ' ');
            });

        return count(longestSent->begin(), longestSent->end(), ' ') + 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}