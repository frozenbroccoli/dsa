#include <iostream>
#include <string>
#include <unordered_map>


int longest_substring_without_repeating_characters(std::string& s) {
	int left = 0, longest = 0;
	std::unordered_map<char, int> window;

	for (int right = 0; right < s.size(); right++) {
		window[s[right]] += 1;
		
		while(window[s[right]] > 1) {
			window[s[left]] -= 1;
			left++;
		}

		longest = std::max(longest, right - (left - 1));
	}
	std::cout << "Input: " << s << " | Result: " << longest << std::endl;
	return longest;
}


int main() {
	std::string s1 = "abcdbea";
	std::string s2 = "aba";
	std::string s3 = "abccabcabcc";
	std::string s4 = "aaaabaaa";
	longest_substring_without_repeating_characters(s1);
	longest_substring_without_repeating_characters(s2);
	longest_substring_without_repeating_characters(s3);
	longest_substring_without_repeating_characters(s4);
}

