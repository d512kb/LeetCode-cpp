// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string generateTag(string caption) {
        string result("#");

        bool word = false;
        for (char c : caption) {
            if (c == ' ') {
                word = true;
                continue;
            }

            if (!isalpha(c)) { continue; }

            if (word) {
                c = toupper(c);
                word = false;
            }
            else {
                c = tolower(c);
            }

            result.push_back(c);
            if (result.size() == 100) { break; }
        }

        result[1] = tolower(result[1]);
        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}