#include <iostream>
#include <vector>


bool is_boundary(std::vector<bool>& arr, int index) {
	return (index == 0 || !arr.at(index - 1));
}


int find_boundary(std::vector<bool>& arr) {
	int left = 0;
	int right = arr.size() - 1;
	
	while (left <= right) {
		int mid = (left + (right - left) / 2);
		std::cout << "Left: " << left << " | Right: " << right << " | Mid: " << mid << std::endl;
		if (arr.at(mid)) {
			if (is_boundary(arr, mid)) return mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}


int main() {
	std::vector<bool> array {false, false, false};
	int boundary = find_boundary(array);
	std::cout << "Boundary: " << boundary << std::endl;
	return 0;
}

