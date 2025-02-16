// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    struct Task {
        int id{};
        int startTime{};
        int processingTime{};
    };
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const int sz = tasks.size();
        vector<Task> tasksToDo;

        for (int i = 0; i < sz; ++i) { tasksToDo.emplace_back(i, tasks[i][0], tasks[i][1]); }
        sort(tasksToDo.begin(), tasksToDo.end(), [](const Task& a, const Task& b) { return a.startTime < b.startTime; });

        auto pqCompare = [](const Task& a, const Task& b) {
            if (a.processingTime == b.processingTime) { return a.id > b.id; }
            return a.processingTime > b.processingTime;
        };

        priority_queue<Task, vector<Task>, decltype(pqCompare)> pq;

        size_t currentTime = 0;
        auto iter = tasksToDo.begin();
        vector<int> result;

        while (iter != tasksToDo.end()) {
            if (pq.empty() && currentTime < iter->startTime) { currentTime = iter->startTime; }

            while (iter != tasksToDo.end() && currentTime >= iter->startTime) {
                pq.emplace(iter->id, iter->startTime, iter->processingTime);
                ++iter;
            }

            result.push_back(pq.top().id);
            currentTime += pq.top().processingTime;
            pq.pop();
        }

        while (!pq.empty()) {
            result.push_back(pq.top().id);
            pq.pop();
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