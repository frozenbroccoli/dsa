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

Node<int>* invert_binary_tree(Node<int>* tree) {
    if (!tree) return nullptr;
    Node<int>* left = invert_binary_tree(tree->left);
    Node<int>* right = invert_binary_tree(tree->right);
    tree->left = right;
    tree->right = left;
    return tree;
}

