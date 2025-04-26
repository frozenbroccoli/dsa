#include <limits>
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


bool dfs(Node<int>* curr, std::pair<int, int> range) {
	if (!curr) return true;
	if (curr->val <= range.first || curr->val >= range.second) return false;
	return dfs(curr->left, {range.first, curr->val}) && 
		dfs(curr->right, {curr->val, range.second});
}


bool valid_bst(Node<int>* root) {
	if (!root) return true;
	return dfs(root->left, {std::numeric_limits<int>::min(), root->val}) && 
		dfs(root->right, {root->val, std::numeric_limits<int>::max()});
}

