// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result{ "" };
        bool blockComment = false;

        for (auto& sourceStr : source) {
            int startFrom = 0;

            if (blockComment) {
                auto termPos = sourceStr.find("*/");
                if (termPos == string::npos) { continue; }
                startFrom = termPos + 2;
                blockComment = false;
            }

            auto& str = result.back();

            for (int i = startFrom; i < sourceStr.size(); ++i) {
                if (blockComment) {
                    auto termPos = sourceStr.find("*/", i);

                    if (termPos == string::npos) { break; }
                    i = termPos + 1; // not +2 because of for loop increase
                    blockComment = false;
                    continue;
                }

                if (sourceStr[i] == '/' || sourceStr[i] == '*') {
                    if (!str.empty() && str.back() == '/') {
                        str.pop_back();
                        if (sourceStr[i] == '/') { // line comment
                            break;
                        } else {
                            blockComment = true;
                            continue;
                        }
                    }
                }

                str.push_back(sourceStr[i]);
            }

            if (!str.empty() && !blockComment) {
                result.emplace_back();
            }
        }

        result.pop_back();
        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}