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
    string minWindow(string s, string t) {
        if (s.size() < t.size() || t.empty())
            return "";

        vector<int> charsData(123, 0);
        vector<int> countChars(123, 0);

        for (const auto& c : t) {
            ++charsData[c];
        }

        int a = 0, b = 0;
        int collected = 0;
        int minLen = s.size()+1;
        pair<int, int> minPos{ a, b };

        while (b < s.size()) {
            const char c = s[b++];

            if (++countChars[c] <= charsData[c]) {
                ++collected;
            }

            while (a < b && collected == t.size()) {
                const char c = s[a];

                if (countChars[c]-- <= charsData[c]) {
                    if (b - a < minLen) {
                        minPos.first = a;
                        minPos.second = b;
                        minLen = b - a;
                    }
                    --collected;
                }

                ++a;
            }
        }

        return { s.begin() + minPos.first, s.begin() + minPos.second };
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
