#include <vector>


int remove_duplicates(std::vector<int>& arr) {
	int pointer1 = 0, pointer2 = 0;
	
	while (pointer1 < arr.size() && pointer2 < arr.size()) {
		if (pointer1 == pointer2) {
			++pointer2;
		} else if (arr.at(pointer1) == arr.at(pointer2)) {
			arr.erase(arr.begin() + pointer2);
		} else {
			++pointer1;
		}
	}

	return arr.size();
}


int remove_duplicates_weird(std::vector<int>& arr) {
	int slow = 0;

	for (int fast = 1; fast < arr.size(); ++fast) {
		if (arr.at(fast) != arr.at(fast - 1)) {
			++slow;
			arr.at(slow) = arr.at(fast);
		} 
	}

	return slow + 1;
}

