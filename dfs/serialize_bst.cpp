#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <iostream>


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


void dfs_serialize(std::string& serialized, Node<int>* curr) {
	if (!curr) {
		serialized += " x";
		return;
	}
	serialized += " " + std::to_string(curr->val);
	dfs_serialize(serialized, curr->left);
	dfs_serialize(serialized, curr->right);
}


Node<int>* dfs_deserialize(std::queue<std::string>& nodes) {
	std::string val = nodes.front();
	nodes.pop();
	if (val == "x") return nullptr;
	Node<int>* curr = new Node(std::stoi(val));
	curr->left = dfs_deserialize(nodes);
	curr->right = dfs_deserialize(nodes);
	return curr;
}


std::string serialize(Node<int>* root) {
	std::string bst = "";
	dfs_serialize(bst, root);
	return bst;
}


Node<int>* deserialize(const std::string& root) {
	std::istringstream bst(root);
	std::queue<std::string> values;
	std::string val;
	while (bst >> val) values.emplace(val);
	return dfs_deserialize(values);
}


int main() {
	Node<int>* bst = deserialize(" 6 4 3 x x 5 x x 8 x x");
	std::cout << serialize(bst) << std::endl;
}

