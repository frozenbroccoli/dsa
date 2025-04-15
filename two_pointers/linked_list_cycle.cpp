template<typename T>
struct Node {
	T val;
	Node<T>* next;

	explicit Node(T val, Node<T>* next = nullptr) 
		: val{val}, next{next} {}
	
	~Node() {
		delete next;
	}
};


bool has_cycle(Node<int>* nodes) {
	Node<int>* leader = nodes;
	Node<int>* follower = nodes;

	while (leader->next != nullptr && leader->next->next != nullptr) {
		leader = leader->next->next;
		follower = follower->next;

		if (leader == follower) { return true; }
	}

	return false;
}

