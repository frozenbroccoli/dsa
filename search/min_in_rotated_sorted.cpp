#include <vector>


int find_min_rotated(std::vector<int>& arr) {
	int left = 0, right = arr.size() - 1, last = right;
	int result;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr.at(mid) <= arr.at(last)) {
			result = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return result;
}

