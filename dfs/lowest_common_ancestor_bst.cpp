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


int lca_on_bst(Node<int>* bst, int p, int q) {
	if (!bst) return -1;
	if (bst->val < p && bst->val < q) {
		return lca_on_bst(bst->right, p, q);
	}

	if (bst->val > p && bst->val > q) {
		return lca_on_bst(bst->left, p, q);
	}

	return bst->val;
}

