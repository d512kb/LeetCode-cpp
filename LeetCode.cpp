// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<char> groups(26);
        iota(begin(groups), end(groups), 0);

        for (auto& equation : equations) {
            if (equation[1] == '=') {
                unite(groups, equation[0] - 'a', equation[3] - 'a');
            }
        }

        for (auto& equation : equations) {
            if (equation[1] == '!') {
                char& firstGroup = groups[equation[0] - 'a'];
                char& secondGroup = groups[equation[3] - 'a'];

                if (findParent(groups, equation[0] - 'a') == findParent(groups, equation[3] - 'a')) {
                    return false;
                }
            }
        }

        return true;
    }
private:
    int findParent(vector<char>& groups, int x) {
        if (groups[x] == x) { return x; }
        groups[x] = findParent(groups, groups[x]);
        return groups[x];
    }
    void unite(vector<char>& groups, int x, int y) {
        int xParent = findParent(groups, x);
        int yParent = findParent(groups, y);

        groups[yParent] = xParent;
    }
};

int main() {
    INIT_TIME(timer);
    
    PRINT_ELAPSED(timer);
    return 0;
}