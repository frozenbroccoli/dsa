#include <vector>
#include <queue>
#include <unordered_set>


int shortest_path(std::vector<std::vector<int>>& graph, int a, int b) {
	if (a < 0 || a >= graph.size() || b < 0 || b >= graph.size()) {
		return -1;
	}

	std::queue<int> nodes;
	int distance {0};
	nodes.push(a);
	std::unordered_set<int> visited {a};

	while (!nodes.empty()) {
		int level_size = nodes.size();

		for (int i = 0; i < level_size; i++) {
			int curr = nodes.front();
			if (curr == b) return distance;
			for (int& neighbor : graph[nodes.front()]) {
				if (!visited.count(neighbor)) {
					nodes.push(neighbor);
					visited.emplace(neighbor);
				}
			}
			nodes.pop();
		}
		distance++;
	}
	return distance;
}

