#include <functional>
#include <vector>
#include <queue>


std::vector<int> heap_top_3(std::vector<int>& arr) {
	std::priority_queue<int, std::vector<int>, std::greater<>> minheap({}, std::move(arr));
	std::vector<int> result;

	for (int i = 0; i < 3; i++) {
		result.push_back(minheap.top());
		minheap.pop();
	}
	return result;
}

