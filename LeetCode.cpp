// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;

        generate(n, n, s, result);

        return result;
    }
private:
    void generate(int a, int b, string& s, vector<string>& result) {
        if (!a && !b) {
            result.push_back(s);
            return;
        }

        if (a) {
            s.push_back('(');
            generate(a - 1, b, s, result);
            s.pop_back();
        }

        if (a < b) {
            s.push_back(')');
            generate(a, b - 1, s, result);
            s.pop_back();
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}
