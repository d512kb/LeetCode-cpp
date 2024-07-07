// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string s1("0");
        string s2("1");

        buildString(n, s1, result);
        buildString(n, s2, result);

        return result;
    }
private:
    void buildString(int n, string& s, vector<string>& result) {
        if (s.size() == n) {
            result.push_back(s);
            return;
        }

        if (s.back() == '0') {
            s.push_back('1');
            buildString(n, s, result);
            s.pop_back();
        } else {
            s.push_back('0');
            buildString(n, s, result);
            s.pop_back();
            s.push_back('1');
            buildString(n, s, result);
            s.pop_back();
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}