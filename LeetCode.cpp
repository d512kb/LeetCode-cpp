// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> sortedWords(9);

        string tmp;
        for (char c : s) {
            if (c == ' ') {
                int pos = tmp.back() - '0';
                tmp.pop_back();
                sortedWords[pos - 1] = std::move(tmp);
            }
            else {
                tmp.push_back(c);
            }
        }

        int pos = tmp.back() - '0';
        tmp.pop_back();
        sortedWords[pos - 1] = std::move(tmp);
        string result;

        for (const string& str : sortedWords) {
            if (str.empty()) { break; }
            result.append(str);
            result.push_back(' ');
        }

        result.pop_back();

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}