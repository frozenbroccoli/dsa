#include <iostream>
#include <vector>


std::vector<int> subarray_sum(std::vector<int>& arr, int target) {
	int sum {0};

	for (int leader = 0, follower = 0; leader < arr.size(); leader++) {
		sum += arr[leader];
		while (sum > target) {
			sum -= arr[follower];
			follower++;
		}

		if (sum == target) {
			return {follower, leader + 1};
		}
	}

	return {};
}


int main() {
	std::vector<int> input {1, -20, -3, 30, 5, 4};
	int target {7};

	std::vector<int> result = subarray_sum(input, target);
	for (int& num : result) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return 0;
}

