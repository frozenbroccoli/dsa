#include <iostream>
#include <vector>
#include <unordered_map>


std::vector<int> subarray_sum_sliding_window(std::vector<int>& arr, int target) {
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


std::vector<int> subarray_sum_prefix_sum(std::vector<int>& arr, int target) {
	std::unordered_map<int, int> prefix_sums {{0, 0}};
	int sum {0};

	for (int leader = 0; leader < arr.size(); leader++) {
		prefix_sums[sum] = leader;
		sum += arr[leader];

		auto it = prefix_sums.find(sum - target);
		if (it != prefix_sums.end()) {
			return {it->second, leader + 1};
		}
	}
	
	return {};
}


int main() {
	std::vector<int> input {1, -20, -3, 30, 5, 7};
	std::vector<int> input2 {1, 1, 1};
	int target1 {7};
	int target2 {3};

	std::cout << "Sliding window: " << std::endl;

	std::cout << "Input 1" << std::endl;
	std::vector<int> result = subarray_sum_sliding_window(input, target1);
	for (int& num : result) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << "Input 2" << std::endl;
	std::vector<int> result2 = subarray_sum_sliding_window(input2, target2);
	for (int& num : result2) {
		std::cout << num << " ";
	}
	std::cout << std::endl;


	std::cout << "Prefix sum: " << std::endl;

	std::cout << "Input 1" << std::endl;
	std::vector<int> result3 = subarray_sum_prefix_sum(input, target1);
	for (int& num : result3) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << "Input 2" << std::endl;
	std::vector<int> result4 = subarray_sum_prefix_sum(input2, target2);
	for (int& num : result4) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}

