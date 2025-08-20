#include <iostream>
#include <vector>
#include <ostream>
#include <exception>
#include <queue>
#include <unordered_map>
#include <unordered_set>

typedef int Node;
typedef std::unordered_map<Node, std::unordered_set<Node>> Graph;
typedef std::vector<Node> Collection;


template<typename T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& set) {
    for (const auto& elem : set) {
        os << elem << " ";
    }
    return os;
}


template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}


template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, V>& map) {
    for (const auto& item : map) {
        os << item.first << ": " << item.second << std::endl;
    }
    return os;
}


struct CollectionHash {
    size_t operator()(const Collection& pos) const noexcept {
        size_t seed {0};
        std::hash<int> hasher;

        for (const auto& elem : pos) {
            seed ^= hasher(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};


struct CollectionEqual {
    bool operator()(const Collection& a, const Collection& b) const noexcept {
        return a == b;
    }
};


Graph build_graph(Collection& nodes, std::vector<Collection>& topologies) {
    Graph graph {};
    for (const auto& node : nodes) {
        graph[node] = {};
    }
    for (const auto& t : topologies) {
        for (int i = 0; i < t.size() - 1; i++) {
            if (graph.count(t[i]) == 0) {
                throw;
            }
            graph[t[i]].insert(t[i + 1]);
        }
    }

    return graph;
}


std::unordered_map<Node, int> find_indegree(Graph& graph) {
    std::unordered_map<Node, int> indegree {};

    for (const auto& entry : graph) {
        indegree[entry.first] = 0;
    }
    for (const auto& entry : graph) {
        for (const auto& dependency : entry.second) {
            indegree[dependency]++;
        }
    }
    return indegree;
}


bool sequence_reconstruction(std::vector<int>& original, std::vector<std::vector<int>>& seqs) {
    try {
        Graph graph = build_graph(original, seqs);
        std::unordered_map<Node, int> indegree = find_indegree(graph);

        std::queue<Node> q;
        for (const auto& node : indegree) {
            if (node.second == 0) q.push(node.first);
        }

        Collection result;

        while (!q.empty()) {
            if (q.size() > 1) return false;

            Node curr = q.front();
            for (const auto& neighbor : graph[curr]) {
                if (--indegree[neighbor] == 0) q.push(neighbor);
            }
            result.emplace_back(curr);
            q.pop();
        }
        return (result == original);

    } catch (std::exception& e) {
    }
    return false;
}


int main() {
    // std::vector<int> original {4, 1, 5, 2, 6, 3};
    // std::vector<std::vector<int>> seqs {{5, 2, 6, 3}, {4, 1, 5, 2}};
    // std::vector<int> original {1, 2, 3};
    // std::vector<std::vector<int>> seqs {{1, 2}, {1, 3}, {2, 3}};
    std::vector<int> original {1, 3, 2};
    std::vector<std::vector<int>> seqs {{1, 2}, {1, 3}};
    bool result = sequence_reconstruction(original, seqs);
    std::cout << "Result: " << std::boolalpha << result << std::endl;
}

