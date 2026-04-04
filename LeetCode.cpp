// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;

        countMode(root, freq);

        int maxFreq = 0;
        for (const auto& [val, freq] : freq) {
            if (freq > maxFreq) { maxFreq = freq; }
        }

        vector<int> result;

        for (const auto& [val, freq] : freq) {
            if (freq == maxFreq) { result.push_back(val); }
        }

        return result;
    }
private:
    void countMode(TreeNode* node, unordered_map<int, int>& freq) {
        if (!node) { return; }

        ++freq[node->val];

        countMode(node->left, freq);
        countMode(node->right, freq);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}