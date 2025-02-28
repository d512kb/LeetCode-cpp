// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> readyServersQueue;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> activeServersQueue;

        for (int i = 0; i < servers.size(); ++i) { readyServersQueue.emplace(servers[i], i); }

        vector<int> result(tasks.size());

        for (int taskIndex = 0, time = 0; taskIndex < tasks.size(); ) {
            time = max(time, taskIndex);

            while (!activeServersQueue.empty() && activeServersQueue.top().first <= time) {
                int serverId = activeServersQueue.top().second;
                activeServersQueue.pop();
                readyServersQueue.emplace(servers[serverId], serverId);
            }

            if (readyServersQueue.empty()) {
                time = activeServersQueue.top().first;
                continue;
            }

            result[taskIndex] = readyServersQueue.top().second;
            activeServersQueue.emplace(time + tasks[taskIndex], readyServersQueue.top().second);
            readyServersQueue.pop();
            ++taskIndex;
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}