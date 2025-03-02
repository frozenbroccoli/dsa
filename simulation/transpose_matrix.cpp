#include <vector>


class Solution {
public:
	std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
		std::vector<std::vector<int>> output;
		for (int i = 0; i < matrix.at(0).size(); ++i) {
			std::vector<int> row;
			for (int j = 0; j < matrix.size(); ++j) {
				row.push_back(matrix.at(j).at(i));
			}
			output.push_back(row);
		}
		return output;
	}
};

