#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>


typedef std::string Node;
typedef std::unordered_map<Node, std::vector<Node>> Graph;


std::ostream& operator<<(std::ostream& os, std::unordered_map<Node, int>& indegree) {
    for (const auto& n : indegree) {
        os << n.first << ": " << n.second << std::endl;
    }
    return os;
}


std::ostream& operator<<(std::ostream& os, Graph& graph) {
    for (const auto& g : graph) {
        os << g.first << ": ";
        for (const auto& n : g.second) {
            os << n << " ";
        }
        os << std::endl;
    }
    return os;
}


Graph generate_graph(
    std::vector<Node>& nodes, 
    std::vector<std::vector<Node>>& connections
) {
    std::unordered_map<Node, std::vector<Node>> graph;
    for (const Node& node : nodes) {
        graph[node] = {};
    }
    for (const auto& connection : connections) {
        Node node = connection[0];
        Node neighbor = connection[1];
        graph[node].emplace_back(neighbor);
    }
    return graph;
}


std::unordered_map<Node, int> find_indegree(Graph graph) {
    std::unordered_map<Node, int> indegree;
    for (const auto& g : graph) {
        indegree[g.first] = 0;
    }
    for (const auto& g : graph) {
        for (const auto& n : g.second) {
            indegree[n]++;
        }
    }
    return indegree;
}


std::vector<std::string> task_scheduling(
    std::vector<std::string>& tasks, 
    std::vector<std::vector<std::string>>& requirements
) {
    Graph graph = generate_graph(tasks, requirements);
    std::unordered_map<Node, int> indegree = find_indegree(graph);
    
    std::cout << graph << std::endl;
    std::cout << indegree << std::endl;

    std::queue<Node> q;
    std::vector<std::string> res;

    for (const auto& node : indegree) {
        if (node.second == 0) q.push(node.first);
    }

    while (!q.empty()) {
        Node curr = q.front();
        for (const auto& neighbor : graph[curr]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) q.push(neighbor);
        }
        res.emplace_back(curr);
        q.pop();
    }
    if (graph.size() == res.size()) return res;

    std::cerr << "Graph contains cycles" << std::endl;
    return {};
}


int main() {
    std::vector<std::string> tasks {"a", "b", "c", "d"};
    std::vector<std::vector<std::string>> requirements {{"a", "b"}, {"c", "b"}, {"b", "d"}};
    std::vector<std::string> res = task_scheduling(tasks, requirements);
    for (const auto& task : res) {
        std::cout << task << " ";
    }
    std::cout << std::endl;
}

