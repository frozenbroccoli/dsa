#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>


bool is_feasible(std::vector<int>& piles, int& hours, int& rate) {
	int hours_spent = 0;

	for (auto pile : piles) {
		while (pile > 0) {
			pile -= rate;
			++hours_spent;
		}
	}
	return hours_spent <= hours;
}

int find_bananas_per_hour(std::vector<int>& piles, int hours) {
	double num_bananas = static_cast<double>(std::accumulate(piles.begin(), piles.end(), 0));
	int left = static_cast<int>(std::ceil(num_bananas / hours));
	int right = *std::max_element(piles.begin(), piles.end());
	int rate = -1;
	int mid;

	while (left <= right) {
		mid = left + (right - left) / 2;
		
		if (is_feasible(piles, hours, mid)) {
			rate = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return rate;
}

int main() {
	std::vector<int> piles {30, 11, 23, 4, 20};
	int h = 6;
	
	int rate = find_bananas_per_hour(piles, h);
	std::cout << rate << std::endl;
}

