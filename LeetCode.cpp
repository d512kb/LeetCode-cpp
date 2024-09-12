// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path{ 0 };

        traverse(graph, path, 0, graph.size() - 1, result);

        return result;
    }
private:
    void traverse(vector<vector<int>>& graph, vector<int>& path, int node, int lastNode, vector<vector<int>>& result) {
        if (node == lastNode) {
            result.push_back(path);
            return;
        }

        for (int sub : graph[node]) {
            path.push_back(sub);
            traverse(graph, path, sub, lastNode, result);
            path.pop_back();
        }
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}