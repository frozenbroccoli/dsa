#include <vector>
#include <unordered_map>
#include <iostream>


int subarray_sum_total(std::vector<int>& arr, int target) {
	std::unordered_map<int, int> sums;
	int sum {0}, count {0};

	for (int i = 0; i < arr.size(); i++) {
		sums[sum] += 1;
		sum += arr[i];

		int complement = sum - target;
		if (sums.count(complement) > 0) {
			count += sums[complement];
		}
	}

	return count;
}


int main() {
	std::vector<int> input {10, 5, -5, -20, 10};
	int target {-10};
	int result = subarray_sum_total(input, target);
	std::cout << "Result: " << result << std::endl;
	return 0;
}

