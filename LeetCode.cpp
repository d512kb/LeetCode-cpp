// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string& str : strs) {
            string s(str);
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>> result;

        for (auto& i : mp) {
            result.push_back(move(i.second));
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
