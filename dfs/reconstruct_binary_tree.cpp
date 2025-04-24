#include <vector>
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


Node<int>* walk(
	std::vector<int>& preorder, 
	std::vector<int>& inorder, 
	int& trav_index, 
	int left, 
	int right
) {
	if (left > right) return nullptr;

	int middle = left - 1;
	auto it = std::find(inorder.begin(), inorder.end(), preorder[trav_index]);
	if (it != inorder.end()) {
		middle = static_cast<int>(std::distance(inorder.begin(), it));
	}
	trav_index++;

	Node<int>* root = new Node(inorder[middle]);
	root->left = walk(preorder, inorder, trav_index, left, middle -1);
	root->right = walk(preorder, inorder, trav_index, middle + 1, right);
	return root;
}


Node<int>* construct_binary_tree(std::vector<int>& preorder, std::vector<int>& inorder) {
	int trav_index = 0, left = 0, right = inorder.size() - 1;
	return walk(preorder, inorder, trav_index, left, right);
}

