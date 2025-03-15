#include <iostream>
#include <vector>


class SnapshotArray {
private:
	int snap_count;
	std::vector<std::vector<std::pair<int, int>>> histories;

public:
	SnapshotArray(int length);
	void set(int index, int val);
	int snap();
	int get(int index, int snap_id);
	void debug();
};


SnapshotArray::SnapshotArray(int length) {
	snap_count = 0;
	histories.assign(length, {{0, 0}});
}

void SnapshotArray::set(int index, int val) {
	std::vector<std::pair<int, int>>& history = histories[index];
	if (history[history.size() - 1].first == snap_count) {
		history[history.size() - 1].second = val; 
	} else {
		history.push_back({snap_count, val});
	}
}

int SnapshotArray::snap() {
	return snap_count++;
}

int SnapshotArray::get(int index, int snap_id) {
	std::vector<std::pair<int, int>>& history = histories[index];
	
	int left = 0, right = history.size() - 1;
	int mid;
	int pos = -1;

	while (left <= right) {
		mid = left + (right - left) / 2;
		if (history[mid].first <= snap_id) {
			pos = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return history[pos].second;
}

void SnapshotArray::debug() {
	std::cout << "[";
	for (auto& vec : histories) {
		std::cout << "[";
		for (auto& pair : vec) {
			std::cout << pair.second << ", ";
		}
		std::cout << "], ";
	}
	std::cout << "]" << std::endl;
}


int main() {
	SnapshotArray arr = SnapshotArray(3);
	arr.debug();

	arr.set(0, 5);
	arr.debug();

	arr.set(0, 9);
	arr.debug();

	int id0 = arr.snap();
	arr.debug();

	arr.set(0, 6);
	arr.debug();

	arr.set(2, 8);
	arr.debug();

	int id1 = arr.snap();
	arr.debug();

	std::cout << "id0: " << id0 << " | id1: " << id1 << std::endl;
	std::cout << arr.get(0, id0) << std::endl;
	std::cout << arr.get(0, id1) << std::endl;
	std::cout << arr.get(2, id1) << std::endl;
	arr.debug();
}

