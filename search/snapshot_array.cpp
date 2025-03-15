#include <iostream>
#include <vector>


class SnapshotArray {
private:
	int snap_count;
	std::vector<std::vector<int>> histories;

public:
	SnapshotArray(int length);
	void set(int index, int val);
	int snap();
	int get(int index, int snap_id);
	void debug();
};


SnapshotArray::SnapshotArray(int length) {
	snap_count = 0;
	histories.assign(length, {0});
}

void SnapshotArray::set(int index, int val) {
	if (snap_count < histories.at(index).size()) {
		histories.at(index).at(snap_count) = val;
	} else {
		histories.at(index).push_back(val);
	}
}

int SnapshotArray::snap() {
	return snap_count++; 
}

int SnapshotArray::get(int index, int snap_id) {
	return histories.at(index).at(snap_id);
}

void SnapshotArray::debug() {
	std::cout << "[";
	for (auto& vec : histories) {
		std::cout << "[";
		for (auto& num : vec) {
			std::cout << num << ", ";
		}
		std::cout << "], ";
	}
	std::cout << "]" << std::endl;
}


int main() {
	SnapshotArray arr = SnapshotArray(3);
	arr.set(0, 5);
	arr.snap();
	arr.set(0, 6);
	std::cout << arr.get(0, 0) << std::endl;
	arr.debug();
}

