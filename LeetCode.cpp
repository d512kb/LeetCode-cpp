// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int sz = rooms.size();
        vector<int> visited(sz);

        return dfs(rooms, visited, 0) == sz;
    }
private:
    int dfs(vector<vector<int>>& rooms, vector<int>& visited, int room) {
        if (visited[room]) {
            return 0;
        }

        visited[room] = 1;
        int roomCount = 1;

        for (int key : rooms[room]) {
            roomCount += dfs(rooms, visited, key);
        }

        return roomCount;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}