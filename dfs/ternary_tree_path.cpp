#include <vector>
#include <string>


template<typename T>
struct Node {
    T val;
    std::vector<Node<T>> children;

    explicit Node(T val, std::vector<Node<T>> children = {})
        : val{val}, children{std::move(children)} {}
};


void dfs(Node<int>& curr_node, std::string& curr_path, std::string& connector, std::vector<std::string>& all_paths) {
	std::string num = std::to_string(curr_node.val);
	curr_path += num + connector;
	if (curr_node.children.empty()) {
		curr_path.erase(curr_path.size() - connector.size());
		all_paths.emplace_back(curr_path);
		curr_path.erase(curr_path.size() - num.size());
		return;
	}

	for (Node<int>& child : curr_node.children) {
		dfs(child, curr_path, connector, all_paths);
	}
	curr_path.erase(curr_path.size() - connector.size() - num.size());
}


std::vector<std::string> ternary_tree_paths(Node<int>& root) {
	std::vector<std::string> result;
	std::string path = "";
	std::string connector = "->";
	dfs(root, path, connector, result);
	return result;
}

