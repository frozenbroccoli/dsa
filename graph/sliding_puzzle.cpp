#include <vector>
#include <iostream>
#include <ostream>
#include <queue>
#include <stdexcept>
#include <utility>
#include <unordered_set>


typedef std::vector<std::vector<int>> Position;
typedef std::pair<int, int> Piece;

std::ostream& operator<<(std::ostream& os, const Position& pos) {
    for (const std::vector<int>& row : pos) {
        for (const int& elem : row) {
            os << elem << " ";
        }
        os << std::endl;
    }
    return os;
}

static constexpr int MIN_ROW {0};
static constexpr int MAX_ROW {1};
static constexpr int MIN_COL {0};
static constexpr int MAX_COL {2};


struct PositionHash {
    size_t operator()(const Position& pos) const noexcept {
        size_t seed {0};
        std::hash<int> hasher;

        for (const std::vector<int>& row : pos) {
            for (const int& elem : row) {
                seed ^= hasher(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
        }
        return seed;
    }
};

struct PositionEqual {
    bool operator()(const Position& a, const Position& b) const noexcept {
        return a == b;
    }
};


Position slide(Position pos, Piece pc) {
    int row {pc.first};
    int col {pc.second};

    if (row < MIN_ROW || row > MAX_ROW || col < MIN_COL || col > MAX_COL) {
        throw std::invalid_argument("Invalid row or column index");
    }

    if (pos[row][col] == 0) throw std::invalid_argument("Empty space cannot be slid");

    std::vector<Piece> adjacents {
        Piece(row + 1, col), 
        Piece(row - 1, col), 
        Piece(row, col - 1), 
        Piece(row, col + 1)
    };

    for (const Piece& adj : adjacents) {
        int adj_row {adj.first};
        int adj_col {adj.second};
        if (adj_row < MIN_ROW || adj_row > MAX_ROW || adj_col < MIN_COL || adj_col > MAX_COL) continue;
        if (pos[adj_row][adj_col] == 0) {
            std::swap(pos[row][col], pos[adj_row][adj_col]);
            return pos;
        }
    }

    throw std::invalid_argument("Piece does not have adjacent empty space");
}


std::vector<Position> get_neighbors(const Position& current) {
    std::vector<Position> neighbors {};

    for (int r = MIN_ROW; r <= MAX_ROW; r++) {
        for (int c = MIN_COL; c <= MAX_COL; c++) {
            Piece pc {r, c};
            try {
                Position neighbor = slide(current, pc);
                neighbors.emplace_back(neighbor);
            } catch (std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

    return neighbors;
}


int bfs(const Position& init_pos, const Position& target) {
    std::queue<Position> q;
    q.push(init_pos);
    std::unordered_set<Position, PositionHash, PositionEqual> visited {init_pos};

    int num_steps {0};
    while (!q.empty()) {
        int level_size = q.size();

        for (int i = 0; i < level_size; i++) {
            Position curr = q.front();
            if (curr == target) return num_steps;

            for (const Position& n : get_neighbors(curr)) {
                if (visited.count(n)) continue;
                q.push(n);
                visited.insert(n);
            }
            q.pop();
        }
        num_steps++;
    }
    return -1;
}


int num_steps(std::vector<std::vector<int>>& init_pos) {
    Position target {{1, 2, 3}, {4, 5, 0}};
    return bfs(init_pos, target);
}


int main() {
    Position init_pos {{4, 1, 3}, {2, 0, 5}};
    int result = num_steps(init_pos);
    std::cout << "Result: " << result << std::endl;
}

