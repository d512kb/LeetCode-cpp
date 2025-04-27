// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> accessTimes;

        for (const auto& time : access_times) {
            accessTimes[time[0]].push_back(getMins(time[1]));
        }

        vector<string> result;

        for (auto& [name, times] : accessTimes) {
            sort(times.begin(), times.end());

            for (int i = 0, j = i + 2; j < times.size(); ++i, ++j) {
                if (times[j] - times[i] < 60) {
                    result.push_back(name);
                    break;
                }
            }
        }

        return result;
    }
private:
    int getMins(const string& time) const {
        return ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + (time[2] - '0') * 10 + (time[3] - '0');
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}