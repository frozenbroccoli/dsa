#include <vector>
#include <string>


void dfs(const std::string& letters, std::string& curr, std::vector<std::string>& permutations, std::vector<bool>& used) {
	if (curr.size() == letters.size()) {
		permutations.emplace_back(curr);
		return;
	}

	for (int i = 0; i < letters.size(); i++) {
		if (used[i]) continue;
		const char& letter = letters[i];
		curr.push_back(letter);
		used[i] = true;
		dfs(letters, curr, permutations, used);
		curr.pop_back();
		used[i] = false;
	}
}


std::vector<std::string> permutations(std::string& letters) {
	std::string curr {""};
	std::vector<std::string> permutations;
	std::vector<bool> used(letters.size(), false);
	dfs(letters, curr, permutations, used);
	return permutations;
}

