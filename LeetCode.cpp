// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<vector<string>> path(bank.size() + 1);
        list<string> genes(bank.begin(), bank.end());

        auto startIter = find(genes.begin(), genes.end(), startGene);
        if (startIter == genes.end()) {
            genes.push_front(startGene);
            startIter = genes.begin();
        }

        auto iter = find(genes.begin(), genes.end(), endGene);
        if (iter != genes.end()) {
            if (startIter == iter)
                return 0;
        } else {
            return -1;
        }

        path[0].push_back(move(*iter));
        genes.erase(iter);
        int index = 1;

        while (!genes.empty()) {
            for (const string& prevGene : path[index - 1]) {
                auto it = genes.begin();

                while (it != genes.end()) {
                    if (calcDiff(prevGene, *it) == 1) {
                        if (startIter == it) { return index; }
                        path[index].push_back(move(*it));
                        it = genes.erase(it);
                    } else {
                        ++it;
                    }
                }
            }

            if (path[index++].empty())
                break;
        }

        return -1;
    }
private:
    int calcDiff(const string& gene1, const string& gene2) {
        int diff = 0;
        for (int i = 0; i < 8; ++i) {
            if (gene1[i] != gene2[i])
                ++diff;
        }
        return diff;
    }
};

int main() {
    INIT_TIME(timer);

    vector<string> bank{ "AACCGATT","AACCGATA","AAACGATA","AAACGGTA" };

    Solution sol;
    int i = sol.minMutation("AACCGGTT", "AAACGGTA", bank);

    PRINT_ELAPSED(timer);
    return 0;
}
