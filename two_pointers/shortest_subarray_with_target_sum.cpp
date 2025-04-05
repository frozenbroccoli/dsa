#include <vector>


int subarray_sum_shortest(std::vector<int>& nums, int target) {
	int leader {0}, sum {0}, result = nums.size();

	for (int follower = 0; follower < nums.size(); follower++) {
		while (sum < target) {
			sum += nums[leader];
			leader++;
		}
		sum -= nums[follower];
		result = std::min(result, leader - follower);
	}

	return result;
}

