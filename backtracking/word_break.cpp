#include <vector>
#include <string>


bool dfs(int start, const std::string& s, std::vector<int>& memo, std::vector<std::string>& words) {
	if (start == s.size()) return true;
	if (memo[start] != -1) return memo[start] == 1;

	int ans = 0;
	for (std::string& word : words) {
		if (s.substr(start).find(word) == 0) {
			if (dfs(start + word.size(), s, memo, words)) {
				ans = 1;
				break;
			}
		}
	}
	memo[start] = ans;
	return ans == 1;
}


bool word_break(std::string& s, std::vector<std::string>& words) {
	std::vector<int> memo(s.size(), -1);
	return dfs(0, s, memo, words);
}

