// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result(s.size()+1, ' '); // extra space to allow iterator increment

        auto outIter = result.begin();
        auto firstChar = s.rbegin();
        auto firstSpace = s.rbegin();
        
        while (true) {
            firstChar = find_if_not(firstSpace, s.rend(), ::isspace);
            firstSpace = find(firstChar, s.rend(), ' ');

            if (firstChar == s.rend())
                break;

            outIter = reverse_copy(firstChar, firstSpace, outIter);
            ++outIter;
        }

        result.resize(distance(result.begin(), outIter)-1);
        
        return result;
    }
};

int main() {
    INIT_TIME(timer);

    Solution sol;

    cout << sol.reverseWords("the sky is blue");

    PRINT_ELAPSED(timer);
    return 0;
}
