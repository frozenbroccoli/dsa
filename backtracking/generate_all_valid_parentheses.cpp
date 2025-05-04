#include <vector>
#include <string>


void dfs(std::string& curr, std::vector<std::string>& all, int& num_openings, int& num_closings, const int& n) {
	if (num_openings == n && num_closings == n) {
		all.emplace_back(curr);
	}

	if (num_openings < n) {
		curr.push_back('(');
		num_openings++;
		dfs(curr, all, num_openings, num_closings, n);
		num_openings--;
		curr.pop_back();
	}

	if (num_closings < num_openings) {
		curr.push_back(')');
		num_closings++;
		dfs(curr, all, num_openings, num_closings, n);
		num_closings--;
		curr.pop_back();
	}
}


std::vector<std::string> generate_parentheses(int n) {
	std::string curr {""};
	std::vector<std::string> result;
	int num_openings {0}, num_closings {0};
	dfs(curr, result, num_openings, num_closings, n);
	return result;
}

