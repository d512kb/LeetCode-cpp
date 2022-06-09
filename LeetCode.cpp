// LeetCode.cpp : Defines the entry point for the application.
//

#include <fstream>
#include <regex>

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
        vector<int> result;

        for (auto &q : queries) {
            if (find_if(lamps.begin(), lamps.end(), [&q](vector<int> lamp) {
                return q.front() == lamp.front() || q.back() == lamp.back() ||
                    abs(q.front() - lamp.front()) == abs(q.back() - lamp.back()); }) != lamps.end()) {
                result.push_back(1);
            } else {
                    result.push_back(0);
                };
                lamps.erase(remove_if(lamps.begin(), lamps.end(), [&q](vector<int> lamp) {
                    return abs(q.front() - lamp.front()) < 2 && abs(q.back() - lamp.back()) < 2;
                                      }), lamps.end());
        }

        return result;
    }
};

void fillVector(const string& line, vector<vector<int>> &vec) {
    regex regex("\\d+,\\d+");
    sregex_iterator regexIter(line.begin(), line.end(), regex);
    auto regexEnd = sregex_iterator();

    for (; regexIter != regexEnd; ++regexIter) {
        auto lampStr = regexIter->str();
        auto commaPos = lampStr.find(',');
        vec.push_back({ stoi(lampStr.substr(0, commaPos)), stoi(lampStr.substr(commaPos+1)) });
    }
}

int main() {

    Solution sol;
	
	vector<vector<int>> lamps;
    vector<vector<int>> queries;

    ifstream f("testcase.txt");
    string line;

    getline(f, line);
    int n = stoi(line);

    getline(f, line);
    fillVector(line, lamps);

    getline(f, line);
    fillVector(line, queries);

    f.close();

    auto start = chrono::steady_clock::now();

    cout << "result: " << sol.gridIllumination(1000000000, lamps, queries).size() << endl;
    cout << "time: " << (chrono::steady_clock::now() - start).count() / 1000000 << "ms";

    return 0;
}
