#include <iostream>
#include <vector>


int container_with_most_water(std::vector<int>& arr) {
	int left = 0, right = arr.size() - 1;
	int val;
	int max = 0;

	while (left < right) {
		val = std::min(arr[left], arr[right]) * (right - left);
		if (val > max) { max = val; }
		if (arr[left] < arr[right]) {
			left++;
		} else {
			right--;
		}
	}
	return max;
}


int main() {
	std::vector<int> input {1, 8, 6, 2, 5, 4, 8, 3, 7};
	std::cout << container_with_most_water(input) << std::endl;
	return 0;
}

