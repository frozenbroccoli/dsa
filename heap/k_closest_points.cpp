#include <vector>
#include <queue>
#include <cmath>


std::vector<std::vector<int>> k_closest_points(
	std::vector<std::vector<int>>& points, 
	int k
) {
	std::vector<std::vector<int>> result;
	auto compare = [](std::vector<int>& a, std::vector<int>& b) {
		return pow(a[0], 2) + pow(a[1], 2) > pow(b[0], 2) + pow(b[1], 2);
	};
	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> minheap(compare, std::move(points));

	for (int i = 0; i < k; i++) {
		result.emplace_back(minheap.top());
		minheap.pop();
	}
	return result;
}

