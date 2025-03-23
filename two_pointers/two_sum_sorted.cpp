#include <vector>


std::vector<int> two_sum_sorted(std::vector<int>& arr, int target) {
	int left = 0, right = arr.size() - 1;
	std::vector<int> result;
	
	while (left < right) {
		if (arr[left] + arr[right] == target) {
			result = std::vector<int> {left, right};			
			break;
		} else if (arr[left] + arr[right] > target) {
			right--;
		} else {
			left++;
		}
	}

	return result;			
}

