#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <functional>
#include <array>
#include <cassert>
#include <exception>
#include <ostream>
#include <unordered_set>
#include <queue>


class CircularInt {
private:
    int v;

public:
    explicit CircularInt() { v = 0; }
    explicit CircularInt(int val) { v = (val % 10 + 10) % 10; }

    friend std::ostream& operator<<(std::ostream& os, const CircularInt& ci) {
        os << ci.v;
        return os;
    }

    bool operator==(CircularInt other) { return v == other.v; }

    friend CircularInt operator+(CircularInt a, int b) {
        return CircularInt(a.v + b);
    }

    friend CircularInt operator-(CircularInt a, int b) {
        return CircularInt(a.v - b);
    }

    friend bool operator==(CircularInt a, CircularInt b) {
        return a.v == b.v;
    }

    friend struct std::hash<CircularInt>;
};


class Position {
private:
    std::array<CircularInt, 4> pos;
    explicit Position(CircularInt a, CircularInt b, CircularInt c, CircularInt d) {
        pos = {a, b, c, d};
    }

public:
    explicit Position(std::string& p) {
        assert(p.size() == 4 && "The position string must contain exactly 4 characters.");
        for (int i = 0; i < 4; i++) {
            try {
                pos[i] = CircularInt(std::stoi(p.substr(i, 1)));
            } catch (std::exception& e) {
                std::cerr << e.what();
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Position& ps) {
        os << "Position(" << ps.pos[0] << ", " << ps.pos[1] << ", " << ps.pos[2] << ", " << ps.pos[3] << ")";
        return os;
    }

    bool operator==(const Position& other) { return pos == other.pos; }

    friend bool operator==(const Position& f, const Position& s) {
        return f.pos == s.pos;
    }

    std::vector<Position> get_neighbors() {
        return {
            Position(pos[0] + 1, pos[1], pos[2], pos[3]),
            Position(pos[0], pos[1] + 1, pos[2], pos[3]),
            Position(pos[0], pos[1], pos[2] + 1, pos[3]),
            Position(pos[0], pos[1], pos[2], pos[3] + 1),
            Position(pos[0] - 1, pos[1], pos[2], pos[3]),
            Position(pos[0], pos[1] - 1, pos[2], pos[3]),
            Position(pos[0], pos[1], pos[2] - 1, pos[3]),
            Position(pos[0], pos[1], pos[2], pos[3] - 1),
        };
    }

    friend struct std::hash<Position>;
};


namespace std {
    template <>
    struct hash<CircularInt> {
        size_t operator()(const CircularInt& c) const {
            return hash<int>()(c.v);
        }
    };

    template <>
    struct hash<Position> {
        size_t operator()(const Position& p) const {
            size_t h = 0;
            for (const auto& c : p.pos) {
                h ^= hash<CircularInt>()(c) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
            return h;
        }
    };
}


int bfs(Position& start, Position& target, std::vector<Position>& traps) {
    std::queue<Position> q;
    std::unordered_set<Position> visited(traps.begin(), traps.end());

    int num_steps {0};
    q.push(start);

    while (!q.empty()) {
        int level_size = q.size();

        for (int i = 0; i < level_size; i++) {
            Position curr = q.front();
            if (curr == target) return num_steps;

            for (const Position& neighbor : curr.get_neighbors()) {
                if (visited.count(neighbor)) continue;
                visited.insert(neighbor);
                q.push(neighbor);
            }
            q.pop();
        }

        num_steps++;
    }

    return -1;
}


int num_steps(std::string& target_combo, std::vector<std::string>& trapped_combos) {
    std::string starting_combo = "0000";
    Position start(starting_combo);
    Position target(target_combo);

    std::vector<Position> traps;
    for (std::string& p : trapped_combos) {
        traps.emplace_back(Position(p));
    }

    return bfs(start, target, traps);
}


int main() {
    std::string target_combo = "0202";
    std::vector<std::string> trapped_combos = {"0201", "0101", "0102", "1212", "2002"};
    int result = num_steps(target_combo, trapped_combos);
    std::cout << "Result: " << result << std::endl;
}

