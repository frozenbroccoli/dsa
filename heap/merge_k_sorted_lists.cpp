#include <vector>
#include <queue>


struct Element {
	int val;
	std::vector<int> current_list;
	int head_index;

	explicit Element(int val, std::vector<int> current_list, int head_index)
		: val{val}, current_list{current_list}, head_index{head_index} {}
};


std::vector<int> merge_k_sorted_lists(std::vector<std::vector<int>>& lists) {
	std::vector<int> result;
	auto compare = [](Element& a, Element& b) {
		return a.val > b.val;
	};
	std::priority_queue<Element, std::vector<Element>, decltype(compare)> minheap(compare);

	for (std::vector<int> list : lists) {
		int val = list[0];
		minheap.emplace(val, std::move(list), 0);
	}

	while (!minheap.empty()) {
		Element e = minheap.top();
		minheap.pop();
		result.emplace_back(e.val);
		e.head_index++;

		if (e.head_index < e.current_list.size()) {
			e.val = e.current_list[e.head_index];
			minheap.emplace(std::move(e));
		}
	}

	return result;
}

