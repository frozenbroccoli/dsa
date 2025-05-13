#include <vector>
#include <string>


void dfs(const std::string& digits, std::vector<int>& memo, int& num_ways, int start) {
	if (start == digits.size()) {
		num_ways += 1;
		return;	
	}

	if (memo[start] != -1) {
		num_ways += memo[start];
		return;
	}

	int curr_digit = std::stoi(digits.substr(start, 1));
	if (curr_digit == 0) return;
	dfs(digits, memo, num_ways, start + 1);

	if (start < digits.size() - 1) {
		curr_digit = std::stoi(digits.substr(start, 2));
		if (curr_digit > 26) return;
		dfs(digits, memo, num_ways, start + 2);
	}

	memo[start] = num_ways;
}


int decode_ways(std::string& digits) {
	std::vector<int> memo(digits.size(), -1);
	int num_ways {0};
	dfs(digits, memo, num_ways, 0);
	return num_ways;
}

