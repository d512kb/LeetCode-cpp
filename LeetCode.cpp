// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> numbers;
        string num;

        for (char c : word) {
            if (isdigit(c)) {
                num.push_back(c);
            }
            else {
                numbers.insert(trimZeroes(num));
                num.clear();
            }
        }

        numbers.insert(trimZeroes(num));
        numbers.erase("");

        return numbers.size();
    }
private:
    string trimZeroes(const string& str) {
        if (str.empty()) { return ""; }

        int pos = 0;
        for (; pos < str.size(); ++pos) {
            if (str[pos] != '0') { break; }
        }

        if (pos == str.size()) { return "0"; }

        return str.substr(pos);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}