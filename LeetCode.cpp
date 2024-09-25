// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;

        for (auto& account : accounts) {
            for (int i = 2; i < account.size(); ++i) {
                string& email1 = account[i - 1];
                string& email2 = account[i];

                graph[email1].push_back(email2);
                graph[email2].push_back(email1);
            }
        }

        vector<vector<string>> result;
        unordered_set<string> visited;

        for (auto& account : accounts) {
            string& name = account[0];
            string& email = account[1];

            vector<string> emails;
            emails.push_back(name);

            getEmails(graph, email, visited, emails);

            if (emails.size() > 1) {
                sort(next(emails.begin()), emails.end());
                result.push_back(move(emails));
            }
        }

        return result;
    }
private:
    void getEmails(unordered_map<string, vector<string>>& graph, string& email, unordered_set<string>& visited, vector<string>& emails) {
        if (visited.contains(email)) { return; }

        visited.insert(email);
        emails.push_back(email);

        for (string& email : graph[email]) {
            getEmails(graph, email, visited, emails);
        }
    }
};

int main() {
    INIT_TIME(timer);
    
    PRINT_ELAPSED(timer);
    return 0;
}