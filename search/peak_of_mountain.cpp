#include <vector>


int peak_of_mountain_array(std::vector<int>& arr) {
	int left = 0, right = arr.size() - 1, last = right;
	int mid, mountain;

	while (left <= right) {
		mid =  left + (right - left) / 2;

		if (arr.at(mid) > arr.at(mid + 1)) {
			mountain = mid;

			if (mid == last - 1) return mountain;

			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return mountain;
}

