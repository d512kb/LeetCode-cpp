// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> listIndexes;

        for (int i = 0; i < list1.size(); ++i) {
            listIndexes[list1[i]] = i;
        }

        int leastIndexSum = list1.size() + list2.size();
        vector<string> result;

        for (int i = 0; i < list2.size(); ++i) {
            auto commonIter = listIndexes.find(list2[i]);

            if (commonIter != listIndexes.end()) {
                if (commonIter->second + i < leastIndexSum) {
                    result.clear();
                    result.push_back(commonIter->first);
                    leastIndexSum = commonIter->second + i;
                }
                else if (commonIter->second + i == leastIndexSum) {
                    result.push_back(commonIter->first);
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