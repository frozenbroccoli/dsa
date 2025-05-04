#include <chrono>
#include <utility>


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


Node<int>* dfs(Node<int>* curr, Node<int>* node1, Node<int>* node2, std::pair<bool, bool>& state) {
	/*
	 * if node1 in left subtree and node2 in right subtree
	 * or node2 in left subtree and node1 in right subtree
	 * or curr == node1 and node2 in either subtree
	 * or curr == node2 and node1 in either subtree
	 * -> answer = curr
	 */
	if (!curr) return nullptr;

	if (curr == node1) {
		state.first = true;
	}
	if (curr == node2) {
		state.second = true;
	}

	if (state.first && state.second) return nullptr;

	Node<int>* left_result = dfs(curr->left, node1, node2, state);
	if (left_result != nullptr) return left_result;

	Node<int>* right_result = dfs(curr->right, node1, node2, state);
	if (right_result != nullptr) return right_result;

	if (state.first && state.second) {
		return curr;
	}
	return nullptr;
}


Node<int>* lca(Node<int>* root, Node<int>* node1, Node<int>* node2) {
	std::pair<bool, bool> state {false, false};
	return dfs(root, node1, node2, state);
}

