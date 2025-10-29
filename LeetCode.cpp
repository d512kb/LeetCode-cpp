// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        int starPos = p.find('*');
        string firstPart = p.substr(0, starPos);
        string secondPart = p.substr(starPos + 1);

        if (firstPart.empty()) { return s.find(secondPart) != string::npos; }
        if (secondPart.empty()) { return s.find(firstPart) != string::npos; }

        int firstPartPos = s.find(firstPart);
        if (firstPartPos == string::npos) { return false; }

        int secondPartPos = s.find(secondPart, firstPartPos + firstPart.size());

        return secondPartPos != string::npos;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}