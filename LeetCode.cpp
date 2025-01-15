// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        const int voteSize = votes.front().size();
        vector<vector<int>> voteTable(voteSize, vector<int>(26));

        for (auto& vote : votes) {
            for (int i = 0; i < voteSize; ++i) {
                ++voteTable[i][vote[i] - 'A'];
            }
        }

        string result;
        transform(votes[0].begin(), votes[0].end(), back_inserter(result), [](char c) { return c - 'A'; });

        sort(result.begin(), result.end(), [&voteTable](char a, char b) {
            for (auto& vote : voteTable) {
                if (vote[a] != vote[b]) { return vote[a] > vote[b]; }
            }

            return a < b;
        });

        transform(result.begin(), result.end(), result.begin(), [](char c) { return c + 'A'; });

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}