// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string reformat(string s) {
        vector<char> chars;
        vector<char> digits;

        for (char c : s) {
            if (isdigit(c)) {
                digits.push_back(c);
            }
            else {
                chars.push_back(c);
            }
        }

        if (abs(static_cast<int>(digits.size()) - static_cast<int>(chars.size())) > 1) { return ""; }

        string ans;

        if (digits.size() > chars.size()) {
            while (digits.size() > 1) {
                ans.push_back(digits.back());
                digits.pop_back();
                ans.push_back(chars.back());
                chars.pop_back();
            }
            ans.push_back(digits.back());
        }
        else {
            while (!digits.empty()) {
                ans.push_back(chars.back());
                chars.pop_back();
                ans.push_back(digits.back());
                digits.pop_back();
            }
            if (!chars.empty()) {
                ans.push_back(chars.back());
            }
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