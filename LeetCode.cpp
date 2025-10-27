// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        const size_t sz = player1.size();
        int p1Score = 0;
        int p2Score = 0;
        array<char, 2> p1PrevScore{};
        array<char, 2> p2PrevScore{};

        for (int i = 0; i < sz; ++i) {
            if (p1PrevScore[0] == 10 || p1PrevScore[1] == 10) {
                p1Score += player1[i] * 2;
            }
            else {
                p1Score += player1[i];
            }

            if (p2PrevScore[0] == 10 || p2PrevScore[1] == 10) {
                p2Score += player2[i] * 2;
            }
            else {
                p2Score += player2[i];
            }

            p1PrevScore[0] = exchange(p1PrevScore[1], player1[i]);
            p2PrevScore[0] = exchange(p2PrevScore[1], player2[i]);
        }

        if (p1Score > p2Score) { return 1; }
        if (p1Score < p2Score) { return 2; }

        return 0;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}