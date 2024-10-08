// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        auto hashAeroport = [](const string& s) -> size_t { return ((s[0] - 'A') << 10) + ((s[1] - 'A') << 5) + (s[2] - 'A'); };
        auto hashTicket = [&hashAeroport](const string& from, const string& to) -> size_t {
            return (hashAeroport(from) << 15) + hashAeroport(to);
        };
        unordered_map<string, set<string>, decltype(hashAeroport)> graph;
        unordered_map<size_t, int> totalTickets; // we will use hashTicket manually

        for (auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
            ++totalTickets[hashTicket(ticket[0], ticket[1])];
        }

        vector<string> result;
        auto dfs = [&](auto&& self, string from, vector<string>& path) -> void {
            if (!result.empty()) { return; }
            if (path.size() == tickets.size() + 1) {
                result = path;
                return;
            }

            for (auto& to : graph[from]) {
                int& haveTickets = totalTickets[hashTicket(from, to)];

                if (haveTickets) {
                    path.push_back(to);
                    --haveTickets;
                    self(self, to, path);
                    path.pop_back();
                    ++haveTickets;
                }
            }
        };

        vector<string> path{ "JFK" };
        dfs(dfs, "JFK", path);

        return result;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}