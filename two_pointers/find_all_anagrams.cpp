#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


std::unordered_map<char, int> read(std::string& input) {
	std::unordered_map<char, int> output;
	for (char& letter : input) {
		output[letter] += 1;
	}
	return output;
}


template<typename key, typename value>
void print_map(std::unordered_map<key, value> input) {
	for (const auto& [k, v] : input) {
		std::cout << k << " -> " << v << std::endl;
	}
}


std::vector<int> find_all_anagrams(std::string& original, std::string& check) {
	int left = 0, right = 0;
	int window_length = check.size();
	std::unordered_map<char, int> window;
	std::vector<int> result;
	std::unordered_map<char, int> check_map = read(check);

	while (right < original.size()) {
		while (right - left < window_length) {
			window[original[right]] += 1;
			right++;
		}
		if (window == check_map) {
			result.push_back(left);
		}
		window[original[left]] -= 1;
		if (window[original[left]] == 0) {
			window.erase(original[left]);
		}
		left++;
	}
	return result;
}


int main() {
	std::string original {"cbaebabacd"};
	std::string check {"abc"};

	std::vector<int> result = find_all_anagrams(original, check);

	std::cout << "Result:" << std::endl;
	for (int& num : result) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

