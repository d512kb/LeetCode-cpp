// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<int>> dependents;
        vector<int> depsCount;

        for (int i = 0; i < recipes.size(); ++i) {
            for (auto& ingred : ingredients[i]) { dependents[ingred].push_back(i); }
            depsCount.push_back(ingredients[i].size());
        }

        queue<string> q(supplies.begin(), supplies.end());
        vector<string> result;

        while (!q.empty()) {
            string ingredientAvailable(std::move(q.front()));
            q.pop();

            for (int dep : dependents[ingredientAvailable]) {
                if (--depsCount[dep] == 0) {
                    q.push(recipes[dep]);
                    result.push_back(recipes[dep]);
                }
            }
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}