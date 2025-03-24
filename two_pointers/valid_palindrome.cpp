#include <iostream>
#include <cctype>
#include <string>


bool is_palindrome(std::string& s) {
	int left = 0, right = s.size() - 1;

	while (left < right) {
		if (!std::isalpha(s[left])) { left++; }
		if (!std::isalpha(s[right])) { right--; }
		if (std::tolower(s[left]) != std::tolower(s[right])) { return false; }
		left++;
		right--;
	}
	return true;
}


int main() {
	std::string s1 {"Do geese see God"};
	std::string s2 {"Was it a car or a cat I saw?"};
	std::string s3 {"A brown fox jumping over"};

	std::cout << is_palindrome(s1) << std::endl;
	std::cout << is_palindrome(s2) << std::endl;
	std::cout << is_palindrome(s3) << std::endl;
	return 0;
}

