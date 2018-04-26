#include "BinarySearchTree.h"

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x, BinaryNode* t) const{
	if(t == nullptr) return false;
	if(t->element == x)
		return true;
	else if(t -> element > x)
		return contains(x, t->left);
	else
		return contains(x, t -> right);
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::findMin(BinaryNode* t) const{
	if(t){
		while(t -> left)
			t = t -> left;
	}
	return t;
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::findMax(BinaryNode* t) const{
	if(t){
		while(t -> right)
			t = t -> right;
	}
	return t;
}

template <typename Comparable>
void BinarySearchTree<Comparable>:: makeEmpty(BinaryNode*& t){
	if(t != nullptr){
		makeEmpty(t -> left);
		makeEmpty(t -> right);
		delete t;
		t = nullptr;
	}
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>:: clone(BinaryNode* t) const{
	if(t == nullptr) return nullptr;
	return new BinaryNode(t -> element, clone(t->left), clone(t->right));
}

template <typename Comparable>
void BinarySearchTree<Comparable>:: insert(const Comparable& x, BinaryNode*& t){
	if(t == nullptr)
		t = new BinaryNode(x);
	else if(x < t->element)
		insert(x, t->left);
	else if(x > t->element)
		insert(x, t->right);
}

template <typename Comparable>
void BinarySearchTree<Comparable>:: insert(Comparable&& x, BinaryNode*& t){
	if(t == nullptr)
		t = new BinaryNode(std::move(x));
	else if(x < t->element)
		insert(std::move(x), t->left);
	else if(x > t->element)
		insert(std::move(x), t->right);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x, BinaryNode*& t){
	if(t == nullptr) return;
	else if(x > t -> element)
		remove(x, t->right);
	else if(x < t -> element)
		remove(x, t->left);
	else if(t -> left && t -> right){
		t -> element = findMin(t->right) -> element;
		remove(t->element, t ->right);
	}
	else{
		BinaryNode* oldt = t;
		t = t -> left? t->left : t->right;
		delete oldt;
	}
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode* t, std::ostream& out) const{
	if(t == nullptr) return;
	printTree(t->left, out);
	out << t->element << std::endl;
	printTree(t->right, out);
}

