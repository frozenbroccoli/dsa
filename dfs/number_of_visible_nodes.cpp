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


void walk(Node<int>* current, int& count, int& ref) {
	if (current == nullptr) return;

	if (current->val >= ref) count++;
	ref = std::max(ref, current->val);
	walk(current->left, count, ref);
	walk(current->right, count, ref);
}


int visible_tree_node(Node<int>* root) {
	if (root == nullptr) return 0;
	int count = 1;
	int ref = root->val;

	walk(root->left, count, ref);
	walk(root->right, count, ref);

	return count;
}

