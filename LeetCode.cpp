// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string, int> assignedCounts;
        vector<string> result;
        result.reserve(names.size());

        for (auto& name : names) {
            auto ins = assignedCounts.emplace(name, 1);

            if (ins.second) {
                result.push_back(name);
            } else {
                int counter = ins.first->second;

                while (!assignedCounts.emplace(std::format("{0}({1})", name, counter), 1).second) {
                    ++counter;
                }

                result.push_back(std::format("{0}({1})", name, counter));
                assignedCounts[name] = ++counter;
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