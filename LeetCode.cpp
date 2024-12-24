// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        using CharCount = pair<int, char>;
        vector<CharCount> chars{ {a, 'a'}, {b, 'b'}, {c, 'c'} };

        string s("  ");

        while (true) {
            sort(chars.begin(), chars.end());
            int sz = s.size();

            for (int i = 2; i >= 0; --i) {
                auto& [cnt, c] = chars[i];

                if (cnt > 0 && (s[sz - 1] != c || s[sz - 2] != c)) {
                    --cnt;
                    s.push_back(c);
                    break;
                }
            }

            if (sz == s.size()) {
                break;
            }
        }

        return s.erase(0, 2);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}