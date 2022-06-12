// LeetCode.cpp : Defines the entry point for the application.
//

#include <fstream>
#include <regex>
#include <set>
#include <map>

#include "LeetCode.h"

using namespace std;

class Solution {
    using IndexedLamps = unordered_map<int, int>;
    using IndexedLampIterator = IndexedLamps::iterator;
    using Index = map<pair<int, int>, vector<pair<IndexedLampIterator, reference_wrapper<IndexedLamps>>>>;

public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
        vector<int> result;

        IndexedLamps lampsCachedRows;
        IndexedLamps lampsCachedCols;
        IndexedLamps lampsCachedLeftDiags;
        IndexedLamps lampsCachedRightDiags;
        Index deleteIndex;

        for (auto &l : lamps) {
            auto lamp = make_pair(l.front(), l.back());

            if (deleteIndex.find(lamp) == deleteIndex.end()) {
                auto iter = lampsCachedRows.insert(make_pair(l.front(), 1));
                if (iter.second) { deleteIndex[lamp].push_back(make_pair(iter.first, ref(lampsCachedRows))); } else { ++iter.first->second; }

                iter = lampsCachedCols.insert(make_pair(l.back(), 1));
                if (iter.second) { deleteIndex[lamp].push_back(make_pair(iter.first, ref(lampsCachedCols))); } else { ++iter.first->second; }

                iter = lampsCachedLeftDiags.insert(make_pair(l.front() - l.back(), 1));
                if (iter.second) { deleteIndex[lamp].push_back(make_pair(iter.first, ref(lampsCachedLeftDiags))); } else { ++iter.first->second; }

                iter = lampsCachedRightDiags.insert(make_pair(l.front() + l.back(), 1));
                if (iter.second) { deleteIndex[lamp].push_back(make_pair(iter.first, ref(lampsCachedRightDiags))); } else { ++iter.first->second; }
            }
        }

        for (auto &q : queries) {
            if (lampsCachedRows.find(q.front()) != lampsCachedRows.end()
                || lampsCachedCols.find(q.back()) != lampsCachedCols.end()
                || lampsCachedLeftDiags.find(q.front() - q.back()) != lampsCachedLeftDiags.end()
                || lampsCachedRightDiags.find(q.front() + q.back()) != lampsCachedRightDiags.end()) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }

            removeIndex(q, deleteIndex);
        }

        return result;
    }

private:
    inline void removeIndex(const vector<int> &index, Index &deleteIndex) {
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                auto iterContainer = deleteIndex.find({ index.front() + i, index.back() + j });
                if (iterContainer != deleteIndex.end()) {
                    for (auto &d : iterContainer->second) { 
                        if (--d.first->second == 0) { 
                            d.second.get().erase(d.first);
                        } 
                    }
                    
                    deleteIndex.erase(iterContainer);
                }
            }
        }
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

    INIT_TIME(timer)

    cout << "result: " << sol.gridIllumination(1000000000, lamps, queries).size() << endl;

    PRINT_ELAPSED(timer)

    return 0;
}
