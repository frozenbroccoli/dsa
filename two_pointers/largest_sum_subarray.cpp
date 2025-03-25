#include <iostream>
#include <vector>
#include <numeric>


int subarray_sum_fixed(std::vector<int>& nums, int k) {
	int follower = 1;
	int max = 0;
	int sum = std::accumulate(nums.begin(), nums.begin() + k, 0);

	for (int leader = follower + k - 1; leader < nums.size(); leader++) {
		sum -= nums[follower - 1];
		sum += nums[leader];
		max = std::max(sum, max);
		follower++;
	}
	return max;
}


int main() {
	std::vector<int> nums {1, 2, 3, 7, 4, 1};
	int k {3};
	std::cout << subarray_sum_fixed(nums, k) << std::endl;
	return 0;
}

