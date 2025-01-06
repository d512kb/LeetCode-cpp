// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<char> aLines{ 0, 0, 0, 0, 0, 0, 0, 0, 'A' }; // 3 horizontal top to bottom, 3 vertical left to right ...
        vector<char> bLines{ 0, 0, 0, 0, 0, 0, 0, 0, 'B' }; // ... and 2 diagonals (left and right) and player ID

        for (auto& move : moves) {
            if (++aLines[move[0]] == 3) { return { aLines.back() }; }
            if (++aLines[3 + move[1]] == 3) { return { aLines.back() }; }
            if (move[0] == move[1] && ++aLines[6] == 3) { return { aLines.back() }; }
            if (move[0] + move[1] == 2 && ++aLines[7] == 3) { return { aLines.back() }; }

            swap(aLines, bLines);
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}