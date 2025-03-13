// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string ipAddress;
        vector<string> result;

        parseOctets(s, 0, 0, ipAddress, result);

        return result;
    }
private:
    void parseOctets(const string& s, int pos, int octetIndex, string& ipAddress, vector<string>& ipAddresses) {
        if (pos == s.size()) {
            if (octetIndex == 4) { // fifth octet means we've built some valid address
                ipAddresses.push_back(ipAddress);
                ipAddresses.back().pop_back(); // remove extra dot
            }

            return;
        }

        int currentOctetValue = 0;
        string currentOctetString;

        for (; pos < s.size(); ++pos) {
            currentOctetValue = currentOctetValue * 10 + (s[pos] - '0');
            currentOctetString.push_back(s[pos]);

            if (currentOctetValue > 255 || (currentOctetString.size() > 1 && currentOctetString[0] == '0')) { break; }

            ipAddress.append(currentOctetString);
            ipAddress.push_back('.');

            parseOctets(s, pos + 1, octetIndex + 1, ipAddress, ipAddresses);

            ipAddress.erase(ipAddress.size() - currentOctetString.size() - 1);
        }
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}