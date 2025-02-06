// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
    using Tree = pair<int, int>;
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        const int sz = trees.size();

        sort(trees.begin(), trees.end());
        vector<Tree> upperFence;
        vector<Tree> bottomFence;

        for (const auto& tr : trees) {
            auto tree = make_pair(tr[0], tr[1]);

            while (upperFence.size() >= 2 && calcAngle(upperFence[upperFence.size() - 2], upperFence.back(), tree) > 0) {
                upperFence.pop_back();
            }

            while (bottomFence.size() >= 2 && calcAngle(bottomFence[bottomFence.size() - 2], bottomFence.back(), tree) < 0) {
                bottomFence.pop_back();
            }

            upperFence.push_back(tree);
            bottomFence.push_back(tree);
        }

        move(bottomFence.begin(), bottomFence.end(), back_inserter(upperFence));
        sort(upperFence.begin(), upperFence.end());
        auto upperFenceEnd = unique(upperFence.begin(), upperFence.end());

        vector<vector<int>> result;
        transform(upperFence.begin(), upperFenceEnd, back_inserter(result), [](const auto& p) { return vector<int>{p.first, p.second}; });

        return result;
    }
private:
    int calcAngle(const Tree& a, const Tree& b, const Tree& c) {
        return (c.second - a.second) * (b.first - a.first) - (b.second - a.second) * (c.first - a.first);
    };
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}