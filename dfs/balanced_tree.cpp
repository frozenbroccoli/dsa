#include <algorithm>


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


bool walk(Node<int>* curr, int& depth, int& leaf_depth) {
	if (!curr) return true;

	depth++;

	leaf_depth = depth;
	if (!walk(curr->left, depth, leaf_depth)) return false;
	int left_leaf_depth = leaf_depth;

	leaf_depth = depth;
	if (!walk(curr->right, depth, leaf_depth)) return false;
	int right_leaf_depth = leaf_depth;

	if (std::abs(left_leaf_depth - right_leaf_depth) > 1) return false;

	leaf_depth = std::max(left_leaf_depth, right_leaf_depth);
	depth--;
	return true;
}


int tree_depth(Node<int>* curr) {
	if (!curr) return 0;
	int left_depth = tree_depth(curr->left);
	int right_depth = tree_depth(curr->right);

	if (left_depth == -1 || right_depth == -1) return -1;
	if (std::abs(left_depth - right_depth) > 1) return -1;

	return std::max(left_depth, right_depth) + 1;
}


bool _is_balanced(Node<int>* tree) {
	int depth {0}, leaf_depth {0};
	return walk(tree, depth, leaf_depth);
}

bool is_balanced(Node<int>* tree) {
	return tree_depth(tree) != -1;
}

