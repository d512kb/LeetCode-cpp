// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        const int k = indices.size();
        const int sz = s.size();
        map<int, int> replaces;

        for (int ind = 0; ind < k; ++ind) {
            int targetIndex = indices[ind];
            auto newReplace = replaces.emplace(targetIndex, ind);

            if (newReplace.second) {
                for (char sourceChar : sources[ind]) {
                    if (targetIndex == sz || s[targetIndex] != sourceChar) {
                        replaces.erase(newReplace.first);
                        break;
                    }
                    ++targetIndex;
                }
            }
        }

        string result;
        int sourceIndex = 0;

        for (auto& replace : replaces) {
            result.append(s, sourceIndex, replace.first - sourceIndex);
            result.append(targets[replace.second]);
            sourceIndex = replace.first + sources[replace.second].size();
        }

        result.append(s, sourceIndex);
        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}