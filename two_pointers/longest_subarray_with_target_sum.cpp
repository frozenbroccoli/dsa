#include <vector>


int subarray_sum_longest(std::vector<int>& nums, int target) {
	int follower {0}, sum {0}, result {0};

	for (int leader {0}; leader < nums.size(); leader++) {
		sum += nums[leader];
		while (sum > target) {
			result = std::max(result, leader - follower);
			sum -= nums[follower];
			follower++;
		}
	}

	return result;
}

