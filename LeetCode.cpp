// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> partitions(n);

        for (int i = 0; i < n; ++i) {
            if (partitions[i] == 0) {
                if (!partition(graph, partitions, i, -1)) {
                    return false;
                }
            }
        }

        return true;
    }
private:
    bool partition(vector<vector<int>>& graph, vector<int>& partitions, int node, int part) {
        if (partitions[node]) { return partitions[node] == part; }

        partitions[node] = part;
        bool canPartition = true;

        for (int neighbor : graph[node]) {
            canPartition = canPartition && partition(graph, partitions, neighbor, -part);
        }

        return canPartition;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}