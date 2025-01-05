// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string validIPAddress(string queryIP) {
        if (checkIPv4(queryIP)) { return "IPv4"; }
        if (checkIPv6(queryIP)) { return "IPv6"; }
        return "Neither";
    }

private:
    bool checkOctet(const string& queryIP, int from, int to) {
        if (to - from < 1 || to - from > 3) { return false; }
        if (to - from > 1 && queryIP[from] == '0') { return false; }

        int num = 0;
        for (int i = from; i < to; ++i) {
            if (queryIP[i] < '0' || queryIP[i] > '9') { return false; }
            num = (num * 10) + queryIP[i] - '0';
        }
        return num <= 255;
    }

    bool checkIPv4(const string& queryIP) {
        int dotPos = -1;
        for (int i = 0; i < 3; ++i) {
            int nextDotPos = queryIP.find('.', dotPos + 1);
            if (nextDotPos == string::npos) { return false; }

            if (!checkOctet(queryIP, dotPos + 1, nextDotPos)) { return false; }
            dotPos = nextDotPos;
        }

        return checkOctet(queryIP, dotPos + 1, queryIP.size());
    }

    bool checkWord(const string& queryIP, int from, int to) {
        if (to - from < 1 || to - from > 4) { return false; }

        for (int i = from; i < to; ++i) {
            char c = queryIP[i];
            const bool isValidChar = (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');

            if (!isValidChar) { return false; }
        }
        return true;
    }

    bool checkIPv6(const string& queryIP) {
        int delimPos = -1;
        for (int i = 0; i < 7; ++i) {
            int nextDelimPos = queryIP.find(':', delimPos + 1);
            if (nextDelimPos == string::npos) { return false; }

            if (!checkWord(queryIP, delimPos + 1, nextDelimPos)) { return false; }
            delimPos = nextDelimPos;
        }

        return checkWord(queryIP, delimPos + 1, queryIP.size());
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}