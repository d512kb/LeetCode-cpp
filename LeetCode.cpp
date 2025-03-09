// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        for (int i = 0; i < fruits.size(); ++i) {
            for (int j = 0; j < baskets.size(); ++j) {
                if (fruits[i] <= baskets[j]) {
                    fruits[i] = 0;
                    baskets[j] = 0;
                    break;
                }
            }
        }

        return count_if(fruits.begin(), fruits.end(), [](int val) { return val > 0; });
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}