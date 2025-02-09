// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        vector<Employee*> graph(2001);

        for (auto empl : employees) {
            graph[empl->id] = empl;
        }

        return calcImportance(graph, id);
    }
private:
    int calcImportance(const vector<Employee*>& employees, int id) {
        if (!employees[id]) { return 0; }

        int importance = employees[id]->importance;

        for (int subId : employees[id]->subordinates) {
            importance += calcImportance(employees, subId);
        }

        return importance;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}