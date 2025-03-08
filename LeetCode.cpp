// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        unordered_map<string, int> digLogsOrder;

        for (int i = 0; i < logs.size(); ++i) {
            if (isdigit(logs[i].back())) {
                digLogsOrder[logs[i]] = i;
            }
        }

        auto sortPred = [&digLogsOrder](const string& log1, const string& log2) {
            bool dig1 = isdigit(log1.back());
            bool dig2 = isdigit(log2.back());

            if (dig1 && dig2) { return digLogsOrder[log1] < digLogsOrder[log2]; }
            if (dig1 || dig2) { return dig2; }

            auto log1ContentPos = 1 + log1.find(' ');
            auto log2ContentPos = 1 + log2.find(' ');

            auto contentCompare = log1.compare(log1ContentPos, log1.size(), log2, log2ContentPos, log2.size());
            if (contentCompare != 0) { return contentCompare < 0; }
            return log1.compare(0, log1ContentPos - 1, log2, 0, log2ContentPos - 1) < 0;
        };

        sort(logs.begin(), logs.end(), sortPred);
        return logs;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}