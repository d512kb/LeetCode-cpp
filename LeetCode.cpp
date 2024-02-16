// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size())
            return -1;

        if (needle.size() <= 1) {
            auto pos = find(haystack.begin(), haystack.end(), needle[0]);

            return pos == haystack.end() ? -1 : distance(haystack.begin(), pos);
        }

        uint32_t k = needle.size();
        uint64_t a = 3;
        uint64_t an = 1;
        uint64_t n = 101;
        uint32_t haystackHash = haystack[k - 1] % n;
        uint32_t needleHash = needle[k-1] % n;

        for (int i = k - 2; i >= 0; --i) {
            an *= a;
            an %= n;
            
            haystackHash = (haystackHash + haystack[i] * an) % n;
            needleHash = (needleHash + needle[i] * an) % n;
        }

        int i = k;

        if (haystackHash == needleHash) {
            if (mismatch(needle.begin(), needle.end(), haystack.begin() + i - k).first == needle.end()) {
                return i - k;
            }
        }

        while (i < haystack.size()) {
            haystackHash = (haystackHash + n - (haystack[i - k] * an) % n) % n;
            haystackHash = (haystackHash * a) % n;
            haystackHash = (haystackHash + haystack[i]) % n;
            
            ++i;

            if (haystackHash == needleHash) {
                if (mismatch(needle.begin(), needle.end(), haystack.begin() + i - k).first == needle.end()) {
                    return i-k;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    string hay(10000000, 'a');
    hay.back() = 'b';
    string needle("aaaab");
    
    INIT_TIME(timer);

    cout << sol.strStr(hay, needle);

    PRINT_ELAPSED(timer);
    return 0;
}
