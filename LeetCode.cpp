// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int index = 0;
        int targetLevel = 0;
        int longestPath = 0;

        traverse(input, index, 0, targetLevel, 0, longestPath);

        return longestPath;
    }
private:
    void traverse(const string& path, int& index, int level, int& targetLevel, int pathLen, int& longestPath) {
        const int sz = path.size();
        int localNameLen = 0;


        while (index < sz) {
            if (level < targetLevel) {
                traverse(path, index, level + 1, targetLevel, pathLen + 1 + localNameLen, longestPath);
            }

            while (level > targetLevel) {
                return;
            }

            if (path[index] == '\n') {
                index += 1; // skip \n
                int nextLevel = 0;

                while (index < sz && path[index] == '\t') { // count tabs
                    index += 1;
                    ++nextLevel;
                }

                targetLevel = nextLevel;
            } else {
                bool file = false;
                localNameLen = 0;

                for (index; index < sz && path[index] != '\n'; ++index, ++localNameLen) {
                    if (path[index] == '.') { file = true; }
                }

                if (file) {
                    longestPath = max(longestPath, pathLen + localNameLen);
                }
            }
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}