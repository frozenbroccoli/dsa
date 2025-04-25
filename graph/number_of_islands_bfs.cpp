#include <vector>
#include <queue>


class Solution {
public:
	struct Coordinate {
		int col;
		int row;
		explicit Coordinate(int x, int y) : col{x}, row{y} {}
	};

	std::vector<Coordinate> get_neighbors(const Coordinate& coord) {
		return {
			Coordinate(coord.col - 1, coord.row),
			Coordinate(coord.col, coord.row + 1),
			Coordinate(coord.col + 1, coord.row),
			Coordinate(coord.col, coord.row - 1)
		};
	}

	void bfs(
		std::vector<std::vector<char>>& grid, 
		std::vector<std::vector<bool>>& visited,
		int& width,
		int& height,
		Coordinate start
	) {
		std::queue<Coordinate> q;
		q.push(start);

		while (!q.empty()) {
			Coordinate curr = q.front();

			for (const Coordinate& neighbor : get_neighbors(curr)) {
				if (
					neighbor.col >= 0 && neighbor.col < width &&
					neighbor.row >= 0 && neighbor.row < height &&
					!visited[neighbor.row][neighbor.col] &&
					grid[neighbor.row][neighbor.col] == '1'
				) {
					visited[neighbor.row][neighbor.col] = true;
					q.push(neighbor);
				}
			}
			q.pop();
		}
	}

	int numIslands(std::vector<std::vector<char>>& grid) {
		int height = grid.size();
		int width = grid[0].size();
		std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
		int island_count {0};
		
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				if (grid[row][col] == '1' && !visited[row][col]) {
					Coordinate curr {col, row};
					bfs(grid, visited, width, height, curr);
					island_count++;
				}
			}
		}
		return island_count;
	}
};

