#include <iostream>
#include <vector>


void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}


void do_quick_sort(std::vector<int>& list, int start_pointer, int end_pointer) {
	if (start_pointer > list.size() - 1 || end_pointer < 1 || start_pointer >= end_pointer) {
		return;
	}

	int initial_start = start_pointer;
	int initial_end = end_pointer;

	int pivot_index = end_pointer;
	int pivot = list.at(pivot_index);

	while (start_pointer != end_pointer) {
		if (list.at(start_pointer) < pivot) {
			++start_pointer;
			continue;
		}

		if (list.at(end_pointer) >= pivot) {
			--end_pointer;
			continue;
		}
		
		swap(list.at(start_pointer), list.at(end_pointer));
	}

	if (pivot_index != end_pointer) {
		swap(list.at(pivot_index), list.at(start_pointer));
	}

	do_quick_sort(list, initial_start, start_pointer - 1);
	do_quick_sort(list, start_pointer + 1, initial_end);
}


std::vector<int> sort_list(std::vector<int>& unsorted_list) {
	do_quick_sort(unsorted_list, 0, unsorted_list.size() - 1);
	return unsorted_list;
}


int main() {
	std::vector<int> vec {14, -9, 4, 21, 7, -14, 8, 7, 7, 2, 3, 2, -2, 5, 4};

	std::cout << std::endl;
	std::cout << "Unsorted list:" << std::endl;
	for (int num : vec) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	do_quick_sort(vec, 0, vec.size() - 1);

	std::cout << std::endl;
	std::cout << "Sorted list:" << std::endl;
	for (int num : vec) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

