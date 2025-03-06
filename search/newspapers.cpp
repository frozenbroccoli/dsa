#include <vector>
#include <numeric>
#include <algorithm>


bool is_feasible(std::vector<int>& nrt, int& nc, int limit) {
	int duration = 0, workers = 0;

	for (auto& time : nrt) {
		if (duration + time > limit) {
			++workers;
			duration = 0;
		}
		duration += time;
	}

	if (duration != 0) {
		++workers;
	}

	return workers <= nc;
}


int newspapers_split(std::vector<int>& newspapers_read_times, int num_coworkers) {
	int low = *std::max_element(newspapers_read_times.begin(), newspapers_read_times.end());
	int high = std::accumulate(newspapers_read_times.begin(), newspapers_read_times.end(), 0);
	int optimal = -1;
	int mid;

	while (low <= high) {
		mid = low + (high - low) / 2;

		if (is_feasible(newspapers_read_times, num_coworkers, mid)) {
			optimal = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return optimal;
}

