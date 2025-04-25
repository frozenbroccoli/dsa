#include <vector>
#include <queue>
#include <unordered_map>


class Solution {
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
		std::vector<int> result;
		result.reserve(k);
		std::unordered_map<int, int> elements;

		for (const int& num : nums) {
			elements[num]++;
		}

		auto compare = [](std::pair<int, int>& a, std::pair<int, int>& b) {
			return a.second > b.second;
		};
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> minheap(compare);

		for (const std::pair<int, int>& element : elements) {
			minheap.emplace(element);

			if (minheap.size() > k) {
				minheap.pop();
			}
		}


		for (int i = 0; i < k; i++) {
			result.emplace_back(minheap.top().first);
			minheap.pop();
		}

		return result;
	}
};

