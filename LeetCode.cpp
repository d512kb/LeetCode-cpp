// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int filledWidth = 0;
        int spacesUsed = 0;
        int wordsAdjusted = 0;
        vector<string> result;

        for (int i = 0; i < words.size(); ++i) {
            filledWidth += words[i].size();

            if (filledWidth + spacesUsed >= maxWidth || i == words.size() - 1) {
                if (filledWidth + spacesUsed > maxWidth) {
                    filledWidth -= words[i].size();
                    --i;
                }

                int unusedSpace = maxWidth - filledWidth;
                int wordsToPlace = i + 1 - wordsAdjusted;
                string justifiedLine;

                if (wordsToPlace > 1) {
                    int spacesPerWord = i == words.size() - 1 ? 1 : unusedSpace / (wordsToPlace - 1);
                    int extraSpace = i == words.size() - 1 ? 0 : unusedSpace % (wordsToPlace - 1);

                    for (int wordIndex = wordsAdjusted; wordIndex < i; ++wordIndex) {
                        justifiedLine += words[wordIndex];
                        justifiedLine.append(spacesPerWord, ' ');
                        if (extraSpace > 0) {
                            justifiedLine.append(" ");
                            --extraSpace;
                        }
                    }

                    justifiedLine += words[i]; // last word in the line

                    if (i == words.size() - 1) {
                        justifiedLine.append(maxWidth - justifiedLine.size(), ' ');
                    }
                } else {
                    justifiedLine += words[i];
                    justifiedLine.append(unusedSpace, ' ');
                }

                result.push_back(std::move(justifiedLine));
                wordsAdjusted += wordsToPlace;
                spacesUsed = 0;
                filledWidth = 0;
            } else {
                ++spacesUsed;
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
