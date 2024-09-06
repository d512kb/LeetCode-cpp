// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size();

        while (left < right) {
            int mid = (left + right) / 2;

            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left < letters.size() ? letters[left] : letters[0];
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}