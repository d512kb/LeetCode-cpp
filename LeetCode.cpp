// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int wastedCustomers = count(customers.begin(), customers.end(), 'Y');
        int wastedHours = 0;
        int penalty = wastedCustomers;
        int result = 0;

        for (int i = 1; i <= customers.size(); ++i) {
            if (customers[i - 1] == 'Y') { --wastedCustomers; } else { ++wastedHours; }

            if (wastedHours + wastedCustomers < penalty) {
                penalty = wastedHours + wastedCustomers;
                result = i;
            }
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