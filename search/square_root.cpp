#include <iostream>


int square_root(int n) {
	int left = 0, right = n;
	int mid, root;

	while (left <= right) {
		mid = left + (right - left) / 2;
		
		if (mid * mid <= n) {
			root = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return root;
}


int main() {
	int input {8};
	int root = square_root(input);
	std::cout << "Input: " << input << " | Root: " << root << std::endl;
}

