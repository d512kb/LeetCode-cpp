// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words(1, "");
        int spacesCount = 0;
        bool wasWord = false;

        for (char c : text) {
            if (c == ' ') {
                ++spacesCount;
                if (wasWord) {
                    wasWord = false;
                    words.emplace_back();
                }
            } else {
                words.back().push_back(c);
                wasWord = true;
            }
        }

        if (words.back().empty()) { words.pop_back(); }

        string result;
        if (words.size() > 1) { spacesCount /= words.size() - 1; }

        result.append(words.front());

        for (int i = 1; i < words.size(); ++i) {
            result.append(spacesCount, ' ');
            result.append(words[i]);
        }

        result.append(text.size() - result.size(), ' ');
        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}