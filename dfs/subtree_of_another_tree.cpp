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


bool search(Node<int>* curr, Node<int>* target) {
	if (!curr || !target) return curr == target;

	if (curr->val == target->val) {
		return (search(curr->left, target->left) && search(curr->right, target->right));
	}

	return (search(curr->left, target) || search(curr->right, target));
}


bool subtree_of_another_tree(Node<int>* root, Node<int>* subroot) {
	return search(root, subroot);
}

