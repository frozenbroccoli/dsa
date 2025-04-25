#include <vector>


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


bool walk(
	std::vector<std::vector<int>>& grid, 
	Coordinate& curr, 
	int& width,
	int& height,
	std::vector<std::vector<bool>>& visited
) {
	if (curr.col < 0 || curr.col >= width || 
		curr.row < 0 || curr.row >= height
	) {
		return false;
	}
	if (visited[curr.row][curr.col]) return false;

	visited[curr.row][curr.col] = true;
	if (grid[curr.row][curr.col] == 0) return false;

	for (Coordinate& neighbor : get_neighbors(curr)) {
		walk(grid, neighbor, width, height, visited);
	}

	return true;
}


int count_number_of_islands(std::vector<std::vector<int>>& grid) {
	int height = grid.size();
	int width = grid[0].size();
	std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
	int island_count {0};	

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			Coordinate coord {col, row};
			if (walk(grid, coord, width, height, visited)) island_count++;
		}
	}

	return island_count;
}

