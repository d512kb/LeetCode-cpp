// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int a = 0;

        while (a < path.size()) {
            int b = path.find('/', a);
            b = b == string::npos ? path.size() : b;
            string s = path.substr(a, b - a);

            if (s == ".." && !v.empty()) {
                v.pop_back();
            } else if (s != ".." && s != "/" && s != "." && !s.empty()) {
                v.push_back(s);
            }

            a = b + 1;
        }

        string result;
        for (string& s : v) {
            result.append("/").append(s);
        }

        return result.empty() ? "/" : result;
    }
};

int main() {
    INIT_TIME(timer);

    Solution sol;
    sol.simplifyPath("/../");

    PRINT_ELAPSED(timer);
    return 0;
}
