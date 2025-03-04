#include <vector>


int find_first_occurrence(std::vector<int>& arr, int target) {
	int left = 0, right = arr.size() - 1;
	int first_true = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr.at(mid) >= target) {
			if (arr.at(mid) == target) {
				first_true = mid;
			}
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return first_true;
}

