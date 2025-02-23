// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct LogRecord {
        int id{ -1 };
        bool start{ false };
        int timestamp{ 0 };
    };
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n);
        stack<int> callStack;
        int markTime = 0;

        for (const auto& log : logs) {
            auto currentCall = parseCall(log);

            if (currentCall.start) {
                if (!callStack.empty()) {
                    result[callStack.top()] += currentCall.timestamp - markTime;
                }

                callStack.push(currentCall.id);
                markTime = currentCall.timestamp;
            } else {
                result[currentCall.id] += currentCall.timestamp - markTime + 1;
                callStack.pop();
                markTime = currentCall.timestamp + 1;
            }
        }

        return result;
    }
private:
    LogRecord parseCall(const string& callRecord) {
        size_t firstColon = callRecord.find(':');
        size_t secondColon = callRecord.find(':', firstColon + 1);

        LogRecord record;

        from_chars(&callRecord[0], &callRecord[firstColon], record.id);
        from_chars(&callRecord[secondColon + 1], &callRecord.back() + 1, record.timestamp);
        record.start = callRecord[firstColon + 1] == 's';

        return record;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}