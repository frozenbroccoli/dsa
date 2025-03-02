#include <iostream>
#include <vector>


void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}


void do_insertion_sort(std::vector<int>& list) {
	for (int i = 1; i < list.size(); ++i) {
		for (int j = i; j > 0; --j) {
			if (list.at(j) < list.at(j - 1)) {
				swap(list.at(j), list.at(j - 1));
			}
		}
	}
}


std::vector<int> sort_list(std::vector<int>& list) {
	do_insertion_sort(list);
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

	do_insertion_sort(vec);

	std::cout << std::endl;
	std::cout << "Sorted list:" << std::endl;
	for (int num : vec) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

