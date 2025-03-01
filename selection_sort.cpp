#include <iostream>
#include <vector>


void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}


void do_selection_sort(std::vector<int>& list) {
	for (int i = 0; i < list.size() - 1; ++i) {
		int min_index = i;

		for (int j = i; j < list.size(); ++j) {
			if (list.at(j) < list.at(min_index)) {
				min_index = j;
			}
		}

		if (i != min_index) {
			swap(list.at(i), list.at(min_index));
		}
	}
}


std::vector<int> sort_list(std::vector<int>& list) {
	do_selection_sort(list);
	return list;
}


int main() {
	std::vector<int> vec {14, -9, 4, 21, 7, -14, 8, 7, 7, 2, 3, 2, -2, 5, 4};

	std::cout << std::endl;
	std::cout << "Unsorted list:" << std::endl;
	for (int num : vec) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	do_selection_sort(vec);

	std::cout << std::endl;
	std::cout << "Sorted list:" << std::endl;
	for (int num : vec) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

