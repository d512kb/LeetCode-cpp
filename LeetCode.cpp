// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int from = 0;

        return parse(s, from);
    }
private:
    string parse(const string& s, int& from) {
        string result;
        string strCount = "0";
        int count = 0;

        for (; from < s.size(); ++from) {
            char c = s[from];

            if (isdigit(c)) {
                strCount += c;
                continue;
            }

            if (c == '[') {
                count = std::stoi(strCount);
                strCount = "0";

                string innerString = parse(s, ++from);

                for (; count > 0; --count) {
                    result += innerString;
                }

                continue;
            }

            if (s[from] == ']') {
                return result;
            }

            result += c;
        }

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}