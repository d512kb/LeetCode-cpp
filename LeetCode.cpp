// LeetCode.cpp : Defines the entry point for the application.
//

#include <vector>

#include "LeetCode.h"

using namespace std;

class Solution {
public:
	static vector<vector<int>> transpose(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return vector<vector<int>>();

		vector<vector<int>> result;
		int colsNumber = matrix.front().size();
		result.reserve(colsNumber);

		for (int colI = 0; colI < colsNumber; ++colI) {
			result.push_back(vector<int>());
			result.back().reserve(matrix.size());
			for (const auto& row : matrix) {
				result[colI].push_back(row[colI]);
			}
		}

		return result;
	}
};

int main()
{
	return 0;
}
