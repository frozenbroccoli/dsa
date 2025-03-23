#include <iostream>
#include <vector>


void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void move_zeros(std::vector<int>& nums) {
	int first = 0, second = 0;

	while (first < nums.size()) {
		if (nums[first] != 0 && nums[second] == 0) {
			swap(nums[first], nums[second]);
			second++;
		} else if (nums[first] == 0 && nums[second] != 0) {
			second = first;
		}
		first++;
	}
}

int main() {
	std::vector arr1 {1, 0, 2, 0, 0, 7};
	move_zeros(arr1);

	for (const int& num : arr1) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	
	return 0;
}

