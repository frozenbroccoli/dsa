#include <iostream>
#include <vector>


int range_sum_query_immutable(const std::vector<int>& nums, int left, int right) {
	std::vector<int> sums(nums.size() + 1, 0);

	for (int i {0}, sum {0}; i < nums.size(); i++) {
		sums[i + 1] = sums[i] + nums[i];
	}

	return sums[right + 1] - sums[left];
}


int main() {
	std::vector<int> input {1, 2, 3, 4};
	int left {1}, right {3};
	int result = range_sum_query_immutable(input, left, right);
	std::cout << "Result: " << result << std::endl;

	return 0;
}

