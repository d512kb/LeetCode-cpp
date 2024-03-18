// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    using Graph = unordered_map<string, unordered_map<string, double>>;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Graph graph;

        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]].emplace(equations[i][0], 1);
            graph[equations[i][1]].emplace(equations[i][1], 1);
            graph[equations[i][0]].emplace(equations[i][1], values[i]);
            graph[equations[i][1]].emplace(equations[i][0], 1 / values[i]);
        }

        vector<double> result;

        for (const auto& query : queries) {
            unordered_set<string> visited;
            double path = findPath(graph, visited, query[0], query[1]);

            result.push_back(path > 0 ? path : -1);
        }

        return result;
    }
private:
    double findPath(const Graph& graph, unordered_set<string>& visited, string a, string b) {
        auto iter = graph.find(a);

        if (iter == graph.end())
            return 0;

        visited.insert(a);

        if (a == b)
            return 1;

        double val = 0;

        for (const auto& neighbor : iter->second) {
            if (!visited.contains(neighbor.first)) {
                val += neighbor.second * findPath(graph, visited, neighbor.first, b);
            }
        }

        return val;
    }
};

int main() {
    INIT_TIME(timer);

    vector<vector<string>> equations{ {"a", "b"}, {"b", "c"}, {"a", "c"}};
    vector<double> values{ 2, 3, 6 };
    vector<vector<string>> queries{ {"a", "c"}, { "b", "a" }, {"a", "e"}, {"a", "a"}, {"x","x"} };

    Solution sol;
    auto result = sol.calcEquation(equations, values, queries);

    PRINT_ELAPSED(timer);
    return 0;
}
