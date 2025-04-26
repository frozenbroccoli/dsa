#include <vector>
#include <string>


bool is_palindrome(const std::string& s) {
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}


void dfs(std::vector<std::string>& partition, std::vector<std::vector<std::string>>& partitions, int start, std::string& s) {
	if (start == s.size()) {
		partitions.emplace_back(partition);
		return;
	}

	for (int end = start; end < s.size(); end++) {
		std::string ss = s.substr(start, end + 1 - start);
		if (!is_palindrome(ss)) {
			continue;
		}
		partition.emplace_back(ss);
		dfs(partition, partitions, end + 1, s);
		partition.pop_back();
	}
}


std::vector<std::vector<std::string>> partition(std::string& s) {
	std::vector<std::vector<std::string>> result;
	std::vector<std::string> partition;
	dfs(partition, result, 0, s);
	return result;
}

