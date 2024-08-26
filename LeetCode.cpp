// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> part;

        buildPartitions(result, part, s, 0, s.size() - 1);

        return result;
    }

private:
    void buildPartitions(vector<vector<string>>& result, vector<string>& part, const string& s, int from, int to) {
        if (from > to) {
            result.push_back(part);
            return;
        }

        for (int i = from; i <= to; ++i) {
            if (isPalindrome(s, from, i)) {
                part.push_back(s.substr(from, i - from + 1));
                buildPartitions(result, part, s, i + 1, to);
                part.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int from, int to) {
        while (from < to) {
            if (s[from++] != s[to--]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}