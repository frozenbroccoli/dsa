#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>


typedef std::string Node;
typedef std::unordered_map<Node, std::unordered_set<Node>> Graph;
typedef std::vector<Node> Collection;


template<typename T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& set) {
    for (const auto& elem : set) {
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
        std::hash<Node> hasher;

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


int task_scheduling_2(
    std::vector<std::string>& tasks, 
    std::vector<int>& times, 
    std::vector<std::vector<std::string>>& requirements
) {
    try {
        std::unordered_map<Node, int> task_times {};
        std::unordered_map<Node, int> distances {};

        for (int i = 0; i < tasks.size(); i++) {
            distances[tasks[i]] = 0;
            task_times[tasks[i]] = times[i];
        }

        Graph graph = build_graph(tasks, requirements);
        std::unordered_map<Node, int> indegree = find_indegree(graph);

        int ans {0};
        std::queue<Node> q;
        for (const auto& node : indegree) {
            if (node.second == 0) {
                q.push(node.first);
                distances[node.first] = task_times[node.first];
                ans = std::max(ans, distances[node.first]);
            }
        }

        while (!q.empty()) {
            Node curr = q.front();
            for (const auto& neighbor : graph[curr]) {
                distances[neighbor] = std::max(distances[neighbor], task_times[neighbor] + distances[curr]);
                ans = std::max(ans, distances[neighbor]);
                if (--indegree[neighbor] == 0) q.push(neighbor);
            }
            q.pop();
        }
        return ans;
    } catch (std::exception& e) {
    }
    return -1;
}

