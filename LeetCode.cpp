// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<pair<int, int>> charPositions(26, { -1, -1 });
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            auto& prevPos = charPositions[s[i] - 'A'];
            ans += (prevPos.second - prevPos.first) * (i - prevPos.second);
            prevPos.first = prevPos.second;
            prevPos.second = i;
        }

        for (auto& charPos : charPositions) {
            ans += (charPos.second - charPos.first) * (s.size() - charPos.second);
        }

        return ans;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}