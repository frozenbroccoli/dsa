template<typename T>
struct ListNode {
	T val;
	ListNode<T>* next;

	explicit ListNode(T val, ListNode<T>* next = nullptr)
		: val{val}, next{next} {}

	~ListNode() {
		delete next;
	}
};


ListNode<int>* revert(ListNode<int>* curr, ListNode<int>*& reverted) {
	if (!curr) return nullptr;
	ListNode<int>* reverted_next = revert(curr->next, reverted);
	if (!reverted_next) {
		reverted = curr;
		return curr;
	}
	reverted_next->next = curr;
	curr->next = nullptr;
	return curr;
}


ListNode<int>* reverse_linked_list(ListNode<int>* head) {
	ListNode<int>* reverted = nullptr;
	revert(head, reverted);
	return reverted;
}

