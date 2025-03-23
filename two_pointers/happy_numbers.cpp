#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>


std::vector<int> parse_digits(int n) {
	std::vector<int> digits;
	int divisor = std::pow(10, static_cast<int>(std::log10(n)));
	int digit;

	while (divisor > 0) {
		digit = n / divisor;
		digits.push_back(digit);
		n %= divisor;
		divisor /= 10;
	}
	return digits;
}

int sum_of_digits_squared(std::vector<int>& digits) {
	int result;
	for (int& digit : digits) {
		result += std::pow(digit, 2);
	}
	return result;
}

bool is_happy_number(int n) {
	std::unordered_map<int, int> window;
	int result = n;

	while (window[1] < 1) {
		std::vector<int> digits = parse_digits(result);
		result = sum_of_digits_squared(digits);
		window[result] += 1;

		if (window[result] > 1) { return false; }
	}

	return true;
}


int main() {
	std::cout << is_happy_number(20) << std::endl;
	std::cout << is_happy_number(912) << std::endl;
	std::cout << is_happy_number(45) << std::endl;
	std::cout << is_happy_number(1) << std::endl;
	std::cout << is_happy_number(93783938) << std::endl;
}

