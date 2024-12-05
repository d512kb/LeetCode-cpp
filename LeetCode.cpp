// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bitset<3> targetNumbers;

        for (auto& triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            }

            targetNumbers.set(0, targetNumbers[0] || triplet[0] == target[0]);
            targetNumbers.set(1, targetNumbers[1] || triplet[1] == target[1]);
            targetNumbers.set(2, targetNumbers[2] || triplet[2] == target[2]);
        }

        return targetNumbers.to_ulong() == 7;
    }
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}