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


Node<int>* insert_bst(Node<int>* bst, int val) {
	if (!bst) return new Node<int>(val);
	if (val < bst->val) {
		bst->left = insert_bst(bst->left, val);
	} else if (val > bst->val) {
		bst->right = insert_bst(bst->right, val);
	}
	return bst;
}

