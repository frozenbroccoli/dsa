#include <vector>
#include <string>


void dfs(std::string& path, std::string& left, std::string& right, std::vector<std::string>& all_paths, int n) {
	if (path.size() == n) {
		all_paths.emplace_back(path);
		path.erase(path.size() - 1);
		return;
	}
	
	std::string left_child = path + left;
	std::string right_child = path + right;

	dfs(left_child, left, right, all_paths, n);
	dfs(right_child, left, right, all_paths, n);

	if (path.size() > 0) {
		path.erase(path.size() - 1);
	}
}


std::vector<std::string> letter_combination(int n) {
	if (n == 0) {
		return {""};
	}
	std::string path = "";
	std::string left = "a";
	std::string right = "b";
	std::vector<std::string> result;

	dfs(path, left, right, result, n);
	return result;
}

