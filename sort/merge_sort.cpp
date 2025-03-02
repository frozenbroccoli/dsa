#include <iostream>
#include <vector>


std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
	std::vector<int> output;
	
	int i = 0, j = 0;
	while (i < a.size() || j < b.size()) {

		if (i >= a.size()) {
			output.push_back(b.at(j));
			++j;
			continue;
		}

		if (j >= b.size()) {
			output.push_back(a.at(i));
			++i;
			continue;
		}

		if (a.at(i) <= b.at(j)) {
			output.push_back(a.at(i));
			++i;
			continue;
		}

		if (b.at(j) < a.at(i)) {
			output.push_back(b.at(j));
			++j;
			continue;
		}
	}
	
	return output;
}


std::vector<int> do_merge_sort(std::vector<int> list) {

	if (list.size() <= 1) {
		return list;
	}

	int mid = list.size() / 2;

	std::vector<int> left = do_merge_sort(std::vector<int>(list.begin(), list.begin() + mid));
	std::vector<int> right = do_merge_sort(std::vector<int>(list.begin() + mid, list.end()));

	return merge(left, right);
}


int main() {
	std::vector<int> vec {5, 3, 1, 2, 4};

	std::cout << std::endl;
	std::cout << "Unsorted list:" << std::endl;
	for (int num : vec) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::vector<int> sorted = do_merge_sort(vec);

	std::cout << std::endl;
	std::cout << "Sorted list:" << std::endl;
	for (int num : sorted) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

