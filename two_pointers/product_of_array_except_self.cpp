#include <iostream>
#include <vector>


std::vector<int> product_of_array_except_self(std::vector<int>& nums) {
	std::vector<int> left_product(nums.size() + 1, 1), right_product(nums.size() + 1, 1);
	std::vector<int> result(nums.size(), 0);
	int i;

	for (i = 0; i < nums.size(); i++) {
		left_product[i + 1] = left_product[i] * nums[i];
	}

	for (i = nums.size(); i >= 0; i--) {
		right_product[i - 1] = right_product[i] * nums[i - 1];
	}

	for (i = 0; i < nums.size(); i++) {
		result[i] = left_product[i] * right_product[i + 1];
	}

	return result;
}


int main() {
	std::vector<int> input {1, 2, 3, 4};
	std::vector<int> output = product_of_array_except_self(input);
	std::cout << "Result: " << std::endl;
	for (int& elem : output) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
	 
	return 0;
}

