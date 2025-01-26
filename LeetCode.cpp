// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers);
        vector<int> offlineTimes(numberOfUsers, numeric_limits<int>::min());

        sort(events.begin(), events.end(), [](const auto& v1, const auto& v2) {
            int t1 = stoi(v1[1]);
            int t2 = stoi(v2[1]);

            if (t1 == t2) { return v1[0][0] == 'O' || v2[0][0] != 'O'; }
            return t1 < t2;
        });

        for (auto& event : events) {
            if (event[0][0] == 'M') {
                auto& mentionStr = event[2];
                int timeStamp = stoi(event[1]);

                if (mentionStr[0] == 'A') {
                    for (int& m : mentions) { ++m; }
                } else if (mentionStr[0] == 'H') {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (offlineTimes[i] + 60 <= timeStamp) { ++mentions[i]; }
                    }
                } else {
                    int start = 0, end = 0;
                    int userId = 0;

                    while ((end = mentionStr.find(' ', start)) != string::npos) {
                        from_chars(&mentionStr[start + 2], &mentionStr[end], userId);
                        ++mentions[userId];
                        start = end + 1;
                    }

                    from_chars(&mentionStr[start + 2], &*mentionStr.end(), userId);
                    ++mentions[userId];
                }
            } else {
                offlineTimes[stoi(event[2])] = stoi(event[1]);
            }
        }

        return mentions;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}