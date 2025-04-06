#include <unordered_map>
#include <vector>
#include <iostream>


int least_consecutive_cards_to_match(std::vector<int>& cards) {
	int follower {0}, result = cards.size() + 1;
	std::unordered_map<int, int> window;

	for (int leader = 0; leader < cards.size(); leader++) {
		window[cards[leader]] += 1;
		while (window[cards[leader]] > 1) {
			result = std::min(result, leader - follower + 1);
			window[cards[follower]] -= 1;
			follower++;
		}
	}
	
	if (result > cards.size()) { result = -1; }
	return result;
}


int main() {
	std::vector<int> input {3, 4, 2, 3, 4, 7};
	int result = least_consecutive_cards_to_match(input);
	std::cout << "Result: " << result << std::endl;
	return 0;
}

