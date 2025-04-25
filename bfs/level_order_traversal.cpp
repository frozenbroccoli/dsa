#include <cmath>
#include <vector>
#include <queue>


template<typename T>
struct Node {
	T val;
	Node<T>* left;
	Node<T>* right;

	explicit Node(T val, Node<T>* left = nullptr, Node<T>* right = nullptr)
		: val{val}, left{left}, right{right} {}

	~Node() {
		delete left;
		delete right;
	}
};


void safe_push(std::queue<Node<int>*>& q, std::vector<int>& v, Node<int>* node) {
	if (node) {
		q.push(node);
		v.emplace_back(node->val);
	}
}


std::vector<std::vector<int>> level_order_traversal(Node<int>* root) {
	if (!root) return {};

	std::queue<Node<int>*> nodes;
	std::vector<std::vector<int>> result;
	std::vector<int> level;
	safe_push(nodes, level, root);
	result.emplace_back(level);

	while (!nodes.empty()) {
		int level_size = nodes.size();
		std::vector<int> level;

		for (int i = 0; i < level_size; i++) {
			safe_push(nodes, level, nodes.front()->left);
			safe_push(nodes, level, nodes.front()->right);
			nodes.pop();
		}
		if (!level.empty()) result.emplace_back(level);
	}
	return result;
}

