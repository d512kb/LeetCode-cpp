// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);

        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        vector<char> visited(n);
        vector<int> lowest(n);
        vector<int> nums(n);
        int num = 0;

        vector<vector<int>> result;
        findCycle(graph, -1, 0, num, visited, nums, lowest, result);

        return result;
    }
private:
    int findCycle(vector<vector<int>>& graph, int prevNode, int node, int& num, vector<char>& visited, vector<int>& nums, vector<int>& lowest, vector<vector<int>>& result) {
        visited[node] = 1;
        ++num;
        nums[node] = num;
        lowest[node] = num;
        int& low = lowest[node];

        for (int near : graph[node]) {
            if (near == prevNode) { continue; }

            if (visited[near]) {
                low = min(low, nums[near]);
            } else {
                low = min(low, findCycle(graph, node, near, num, visited, nums, lowest, result));
            }

            if (nums[node] < lowest[near]) {
                result.push_back({ node, near });
            }
        }

        return low;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}