#include <vector>
#include <string>


class Solution {
public:
	std::vector<std::string> fizzBuzz(int n) {
		std::vector<std::string> output;
		for (int i = 1; i <= n; ++i) {
			if (i % 15 == 0) {
				output.push_back("FizzBuzz");
			} else if (i % 3 == 0) {
				output.push_back("Fizz");
			} else if (i % 5 == 0) {
				output.push_back("Buzz");
			} else {
				output.push_back(std::to_string(i));
			}
		}
		return output;
	}
};

