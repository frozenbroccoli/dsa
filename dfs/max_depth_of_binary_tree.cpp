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


void walk(Node<int>* current, int& height, int& max_height) {
	if (current == nullptr) return;

	height++;
	max_height = std::max(height, max_height);

	walk(current->left, height, max_height);
	walk(current->right, height, max_height);

	height--;
}


int tree_max_depth(Node<int>* root) {
	if (root == nullptr) return 0;

	int max_height = 0, height = 0;
	walk(root->left, height, max_height);
	walk(root->right, height, max_height);

	return max_height;
}

