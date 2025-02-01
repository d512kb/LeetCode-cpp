// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> result(deck.size());

        queue<int> q;
        for (int i = 0; i < deck.size(); ++i) {
            q.push(i);
        }

        for (int i = 0; i < deck.size(); ++i) {
            result[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}