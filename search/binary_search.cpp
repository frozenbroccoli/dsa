#include <vector>


int do_binary_search(std::vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;

	while(left <= right) {
		int midpoint = (left + right) / 2;

		if (arr.at(midpoint) == target) {
			return midpoint;
		} else if (arr.at(midpoint) < target) {
			left = midpoint + 1;
		} else {
			right = midpoint - 1;
		}
	}
	return -1;
}

