#include <vector>
#include <unordered_map>


std::pair<int, int> two_sum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> seen;
	for (int i = 0; i < nums.size(); i++) {
		if (seen.count(target - nums[i])) return {i, seen[target - nums[i]]};
		seen[nums[i]] = i;
	}
	return {};
}

