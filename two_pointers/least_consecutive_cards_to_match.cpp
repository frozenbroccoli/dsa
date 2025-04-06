#include <unordered_map>
#include <vector>
#include <iostream>


int least_consecutive_cards_to_match(std::vector<int>& cards) {
	int follower {0}, result = cards.size() + 1;
	std::unordered_map<int, std::pair<int, int>> window;

	for (int leader = 0; leader < cards.size(); leader++) {
		window[cards[leader]].second += 1;
		if (window[cards[leader]].second > 1) {
			result = std::min(result, leader - window[cards[leader]].first + 1);

			while (follower < window[cards[leader]].first) {
				window[cards[follower]].second -= 1;
				follower++;
			}
		}
		window[cards[leader]].first = leader;
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

