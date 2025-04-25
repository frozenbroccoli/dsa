#include <vector>
#include <queue>


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


std::vector<std::vector<int>> flood_fill(
	int r, 
	int c, 
	int replacement,
	std::vector<std::vector<int>>& image
) {
	int height = image.size();
	int width = image[0].size();
	Coordinate root {c, r};
	std::queue<Coordinate> q;
	q.push(root);

	std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
	int root_val = image[r][c];
	visited[r][c] = true;

	while(!q.empty()) {
		Coordinate curr = q.front();

		for (Coordinate& neighbor : get_neighbors(curr)) {
			if (
				neighbor.row >= 0 && neighbor.row < height &&
				neighbor.col >= 0 && neighbor.col < width &&
				!visited[neighbor.row][neighbor.col] && 
				image[neighbor.row][neighbor.col] == root_val
			) {
				q.push(neighbor);
				visited[neighbor.row][neighbor.col] = true;
			}
		}

		image[curr.row][curr.col] = replacement;
		q.pop();
	}
	return image;
}

