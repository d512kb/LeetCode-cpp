// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        array<uint8_t, 256> trans{};
        for (uint16_t from = 0; from < 256; ++from) {
            uint8_t to = 0;

            for (int k = 1; k < 7; ++k) {
                to |= (~(((from >> (k - 1)) & 1) ^ ((from >> (k + 1)) & 1)) & 1) << k;
            }

            trans[from] = to;
        }

        uint8_t cellsRow = 0;
        for (int i = 0; i < 8; ++i) { cellsRow |= cells[i] << (7 - i); }

        array<int, 256> seen{};
        vector<uint8_t> chain;

        while (n--) {
            cellsRow = trans[cellsRow];

            if (seen[cellsRow] > 0) {
                int cycleSize = chain.size() - seen[cellsRow];
                cellsRow = chain[seen[cellsRow] + n % cycleSize];
                break;
            }

            chain.push_back(cellsRow);
            seen[cellsRow] = chain.size() - 1;
        }

        for (int i = 0; i < 8; ++i) { cells[i] = (cellsRow >> 7 - i) & 1; }

        return cells;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}