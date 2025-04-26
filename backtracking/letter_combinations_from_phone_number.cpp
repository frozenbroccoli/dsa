#include <vector>
#include <string>
#include <unordered_map>


const std::unordered_map<char, std::string> keyboard = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};


void dfs(std::string& digits, std::vector<char>& combination, std::vector<std::string>& combinations, int i) {
	if (combination.size() == digits.size()) {
		std::string s(combination.begin(), combination.end());
		combinations.emplace_back(s);
		return;
	}

	for (const char& c : keyboard.at(digits[i])) {
		combination.emplace_back(c);
		dfs(digits, combination, combinations, i + 1);
		combination.pop_back();
	}
}


std::vector<std::string> letter_combinations_of_phone_number(std::string& digits) {
	std::vector<char> combination;
	std::vector<std::string> combinations;
	dfs(digits, combination, combinations, 0);
	return combinations;
}

